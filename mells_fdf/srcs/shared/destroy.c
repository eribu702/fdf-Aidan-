/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:39:28 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(t_map **map)
{
	free((*map)->altitude);
	free((*map)->colours);
	*map = NULL;
}

static void	free_hooks(t_hook **events)
{
	t_hook	*curr;

	curr = *events;
	while (curr)
	{
		(*events) = (*events)->next;
		free(curr);
		curr = (*events);
	}
	*events = NULL;
}

void	destroy(int key_press, void *param)
{
	t_fdf	*fdf;

	if (key_press == -1 || key_press == MAC_ESC || key_press == LI_ESC)
	{
		fdf = (t_fdf *)param;
		if (fdf->img.img)
			mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		free(fdf->mlx);
		free_map(&fdf->map);
		free_hooks(&fdf->events);
		terminate(EXIT, 0);
	}
	terminate(gen_error_msg(ERR_MSG, MACROS), 1);
}

int	x_close_win(void *param)
{
	destroy(-1, param);
	return (0);
}
