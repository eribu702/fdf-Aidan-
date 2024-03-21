/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:52:04 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/21 16:57:00 by aroberts         ###   ########.fr       */
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
			head = (*stack)->next;
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
		new->next = *data;
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
	tmp->next = NULL;
	push_to_stack(tmp, data);
	return (true);
}

static t_stack	*current_stack(t_stack **data)
{
	t_stack	*head;

	head = NULL;
	if (data && *data)
	{
		head = *data;
		*data = (*data)->next;
	}
	return (head);
}

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
	head = current_stack(&data);
	while (head && i >= 0)
	{
		(*map)->altitude[i] = head->z;
		(*map)->colours[i] = head->colour;
		if (head->z > (*map)->z_max)
			(*map)->z_max = head->z;
		if (head->z > (*map)->z_min)
			(*map)->z_min = head->z;
		head = current_stack(&data);
		i--;
	}
	(*map)->z_range = (*map)->z_max - (*map)->z_min;
}
