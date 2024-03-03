/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2023/11/01 12:28:28 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int key_press, void *param)
{
	t_hook	*event;
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	event = fdf->events;
	while (event)
	{
		if (key_press == event->key_press)
		{
			(event->function)(key_press, fdf);
			render_fdf(fdf);
			break ;
		}
		event = event->next;
	}
	return (0);
}

static void	add_hook(t_hook **events, int key_press, void (*f)())
{
	t_hook	*new_event;
	t_hook	*curr;

	curr = *events;
	new_event = (t_hook *)malloc(sizeof(t_hook));
	if (!new_event)
		terminate(gen_error_msg(ERR_MSG, MALLOC), 1);
	new_event->key_press = key_press;
	new_event->function = f;
	new_event->next = NULL;
	if (!curr)
		(*events) = new_event;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new_event;
	}
}

static void	load_linux_keys(t_hook **events)
{
	add_hook(events, LI_ESC, destroy);
	add_hook(events, LI_PLUS, update_zoom);
	add_hook(events, LI_MINUS, update_zoom);
	add_hook(events, LI_W, update_rot);
	add_hook(events, LI_A, update_rot);
	add_hook(events, LI_S, update_rot);
	add_hook(events, LI_D, update_rot);
	add_hook(events, LI_Q, update_rot);
	add_hook(events, LI_E, update_rot);
	add_hook(events, LI_ARROW_U, pan_movement);
	add_hook(events, LI_ARROW_L, pan_movement);
	add_hook(events, LI_ARROW_D, pan_movement);
	add_hook(events, LI_ARROW_R, pan_movement);
	add_hook(events, LI_R, reset_default);
	add_hook(events, LI_I, change_projection);
	add_hook(events, LI_O, change_projection);
	add_hook(events, LI_P, change_projection);
}

static void	load_mac_keys(t_hook **events)
{
	add_hook(events, MAC_ESC, destroy);
	add_hook(events, MAC_PLUS, update_zoom);
	add_hook(events, MAC_MINUS, update_zoom);
	add_hook(events, MAC_W, update_rot);
	add_hook(events, MAC_S, update_rot);
	add_hook(events, MAC_A, update_rot);
	add_hook(events, MAC_D, update_rot);
	add_hook(events, MAC_Q, update_rot);
	add_hook(events, MAC_E, update_rot);
	add_hook(events, MAC_ARROW_U, pan_movement);
	add_hook(events, MAC_ARROW_D, pan_movement);
	add_hook(events, MAC_ARROW_L, pan_movement);
	add_hook(events, MAC_ARROW_R, pan_movement);
	add_hook(events, MAC_R, reset_default);
	add_hook(events, MAC_I, change_projection);
	add_hook(events, MAC_O, change_projection);
	add_hook(events, MAC_P, change_projection);
}

void	load_event_hooks(t_fdf *fdf)
{
	t_hook	*events;

	events = NULL;
	if (KEYS == 1)
		load_linux_keys(&events);
	else if (KEYS == 2)
		load_mac_keys(&events);
	else
		terminate(gen_error_msg(ERR_MSG, MACROS), 1);
	mlx_hook(fdf->win, 2, 1l << 0, key_handler, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, x_close_win, fdf);
	fdf->events = events;
}
