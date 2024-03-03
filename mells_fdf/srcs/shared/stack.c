/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:45:08 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
 * 	Add to top of linked list function.
 * 		Initialises "data" node if one doesnt already exist.
 * 		Links "new" node to "data" pointer.
 * 		Sets "data" node pointer to "new" node.
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
 * 	Gets map data from split array, converts to integers, pushes to stack.
 * 		Allocate memory for all tmp stack values.
 * 		** Map file is formatted so the coordinate then the colour are specified.
 * 		Seperated by a ',' **
 * 		Convert 1st split value and store it in 'z'.
 * 		Convert 2nd split value and store in in 'colour'.
 * 		Set 'next' pointer to NUll, Last value on stack.
 * 		Re-link stack with function.
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
		tmp->colour = hex_atoi(values[1]);
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
		terminate(gen_error_msg(ERR_MSG, STACK), 1);
	size = (*map)->width * (*map)->height;
	(*map)->altitude = (int *)ft_calloc(size, sizeof(int));
	(*map)->colours = (int *)ft_calloc(size, sizeof(int));
	if (!(*map)->altitude || !(*map)->colours)
		terminate(gen_error_msg(ERR_MSG, MALLOC), 1);
	i = size - 1;
	head = current_stack(&data);
	while (head && i >= 0)
	{
		(*map)->altitude[i] = head->z;
		(*map)->colours[i] = head->colour;
		if (head->z > (*map)->z_max)
			(*map)->z_max = head->z;
		if (head->z < (*map)->z_min)
			(*map)->z_min = head->z;
		head = current_stack(&data);
		i--;
	}
	(*map)->z_range = (*map)->z_max - (*map)->z_min;
}
