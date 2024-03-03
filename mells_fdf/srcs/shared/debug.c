/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:32:37 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_stack(t_stack *data, t_map *map)
{
	int		x;
	int		y;
	t_stack	*display;

	y = 0;
	display = data;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (display->z > 9)
				ft_printf("%d ", display->z);
			else
				ft_printf(" %d ", display->z);
			display = display->next;
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n\n");
}

void	print_array(int *array, t_map *map)
{
	int	i;
	int	j;

	if (array)
	{
		i = 0;
		j = 0;
		ft_printf("\n\n");
		while (i < (map->width * map->height))
		{
			if (j == map->width)
			{
				ft_printf("\n");
				j = 0;
			}
			if (array[i] > 9)
				ft_printf("%d ", array[i]);
			else
				ft_printf(" %d ", array[i]);
			j++;
			i++;
		}
		ft_printf("\n\n");
	}
}

void	check_hooks(t_hook *list)
{
	int		i;
	t_hook	*curr;

	if (!list)
	{
		ft_printf("List is empty!\n");
		return ;
	}
	curr = list;
	i = 0;
	while (curr)
	{
		ft_printf("[%d] > {%d}\n", i, curr->key_press);
		i++;
		curr = curr->next;
	}
}
