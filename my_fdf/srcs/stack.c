/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:52:04 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/22 17:29:00 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
our function free_stack frees a stack from its
given node onwards. we create teporary
node head, and set it to NULL.
then we check if there is data in the parameter
stack, and if there is we begin a while loop
that will continue until the current node (*stack)
is empty. while its running, we assign the next node
to head, free our current stack, and then set it to
= head, or its next node rather. this is
the equivalent of emptying a node and moving
on to the next one, and repeating. after this,
we free *stack, which should be empty, but this
ensures we dont have memory leaks. and we set it
to NULL.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*head;

	head = NULL;
	if (*stack)
	{
		while (*stack != NULL)
		{
			head = (*stack)->last;
			free(*stack);
			*stack = head;
		}
		free(*stack);
		*stack = NULL;
	}
}

/*
our function push to stack takes a new
node of data and pushes it to a pre-existing stack.
new is the new node, and **data should point to the
head (the top) of a pre-existing stack.

if data == null
	data = new
basically checks if the top of the pre-existing
stack is empty or not. if its empty, it puts the new
data on the current head. otherwise,
we set the new node to point to the 'current' data,
and move the stack to point to the new node,
effectively adding a new node onto a pre-existing stack.
*/
static void	push_to_stack(t_stack *new, t_stack **data)
{
	if (data == NULL)
		*data = new;
	else
	{
		new->last = *data;
		*data = new;
	}
}

/*
okay, here we go. char **values contains an array of strings.
these strings contain numbers from the negatives to the triple digits.
these digits are there to represent z, or our codes way of
raising/lowering parts of our wireframe map. negatives lower it,
and positives raise it, and 0 leaves it normal.
some of these values look like this though: 5,0xFF102938
or something like that. that is a z value, and a hex value (for colour)
seperated by a comma. in our parent function, we format this infor-
mation and there are no more spaces or commas. values[0] refers to
the z value, and values[1] refers to the hex value. most
map files have z values with no hex.

save_to_stack takes **values (array of strings), and **data,
a linked list to add the data in values to. we create a temporary
stack node, and allocate it memory. we error check, and then begin ;)
we set tmp->z to the int version of the number in values[0].
and then we check if there is a colour value, if not then
tmp->colour = -1, otherwise we use ft_hex_atoi, which takes
a char * hex value "0xXXXXXXXX" and converts it into its int value
and set that int value to tmp->colour.
we then use valid_int on tmp->z & colour, which is a boolean
function that makes sure the intergers are valid, and if that
passes we push to stack and return true, otherwise, false.
*/
bool	save_to_stack(char **values, t_stack **data)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!*values || !tmp)
		return (false);
	tmp->z = ft_atoi(values[0]);
	if (!values[1])
		tmp->colour = -1;
	else
		tmp->colour = ft_hex_atoi(values[1]);
	if (!valid_int(tmp->z) || !valid_int(tmp->colour))
		return (false);
	tmp->last = NULL;
	push_to_stack(tmp, data);
	return (true);
}

/*
this function removes or bumps a node off the stack.
we create a new node head, and set it to NULL.
we run an if check, the first one checks that there
is a **data at all, and the second if there is anything
in the last node, this is because checking for *data
is a dereference and looking for it when there isnt **data
in the first place would seg fault.
if the checks pass,  we set head to equal the information
in data, and make data point to ->last. this removes
the top node off the stack, stores it in head, and returns
it in case we want to not only remove a node but access its data.
otherwise we return head, which is the equivalent of returning
NULL, and is an accurate and simple way to reflect an error state.
*/
static t_stack	*remove_node(t_stack **data)
{
	t_stack	*head;

	head = NULL;
	if (data && *data)
	{
		head = *data;
		*data = (*data)->last;
	}
	return (head);
}

/*
another fun one!
here we go:
stack_to_arrays takes a t_stack *data, this has within it
all of our parsed and stack-E-fied information from
our map file. its now time to take this simple information,
(an int for the height of the node on the map, and an int
for the colour of the node) and make it alot more complicated!
in our map structure, we have some simple data we need to collect
from all this information, this is stuff like z_max (highest point
on map), z_min, (lowest), z_range (the difference between the two
and the range from lowest to highest). we already have the width
and height of the map and the 'file'. all thats left is
*altitude and *colours. just like a str *, these are int *,
or an array of intergers. we use [i] to iterate through them
and fill them with all the z(altitude) and colour values respectively.
we declare an i for iterating, a size_t size to find out the amount
of pixels or bytes the map has, and t_stack head to use our data stack.
we check that there is data, and terminate if not. otherwise, we set size
to = the width times the height of the map. we then allocate memory
to *altitude and *colours so they can hold all the data. we check again,
and if there are no errors, we make i = size - 1. this is because
like normal iterating, 0 refers to the first element, 1 the second and so
on. so if we have 30 bytes in size, we will need i to = 29. we are also
using a linked list that is linked backwards, or whatever, its called
a (Last in, first out (LIFO)) or something, meaning we add more things on
to the stack, and have to remove them in reverse order. the top of
the stack has the last thing we have added to it, so to go through
the data, we iterate backwards.
we then make head = remove_node(&data), which pops off the last node,
and puts it on to head, we can keep using remove_node() to keep
popping off more nodes, and one by one going backwards using
our stacked data while also popping the old ones off as we go.
we enter a while loop that will continue while i is still decrementing
or while there is still data on the stack, and we set the colour[i] and
altitude[i] to = the data temporarily stored in stack. we do a couple
ifs that will update z_max and z_min whenever they encounter a z
that is higher or lower than they are at the moment (theyre both 0
to begin with.). we then set head to equal the next node and pop it
off and decrement i, then repeat. when the loop breaks, we set z_range
to = z_max - z_min.
*/
void	stack_to_arrays(t_stack *data, t_map **map)
{
	int		i;
	size_t	size;
	t_stack	*head;

	if (!data)
		terminate(gen_error_msg(ERR, STACK), 1);
	size = (*map)->width * (*map)->height;
	(*map)->altitude = (int *)ft_calloc(size, sizeof(int));
	(*map)->colours = (int *)ft_calloc(size, sizeof(int));
	if (!(*map)->altitude || !(*map)->colours)
		terminate(gen_error_msg(ERR, MALLOC), 1);
	i = size - 1;
	head = remove_node(&data);
	while (head && i >= 0)
	{
		(*map)->altitude[i] = head->z;
		(*map)->colours[i] = head->colour;
		if (head->z > (*map)->z_max)
			(*map)->z_max = head->z;
		if (head->z < (*map)->z_min)
			(*map)->z_min = head->z;
		head = remove_node(&data);
		i--;
	}
	(*map)->z_range = (*map)->z_max - (*map)->z_min;
}
