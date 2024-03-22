/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:20:22 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/22 15:19:10 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* this function simply iterates though our hooks
linked list, and frees it (deallocates) until it reaches the end.
*/
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

/* destroy takes an int key_press to make sure that ESC has
been pressed, or that the function has been run from
x_close_win. once it has initalized an fdf struct
and checked that it has been run correctly, it will
assign the new struct to point to our original fdf,
then it checks if fdf has an image. if fdf has an image
it will destroy that image, and then destroy the window.
it will then free mlx from its allocation, and terminate
the project.
*/
void	destroy(int key_press, void *param)
{
	t_fdf	*fdf;

	if (key_press == -1 || key_press == 53)
	{
		fdf = (t_fdf *)param;
		if (fdf->img.img)
			mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		free(fdf->mlx);
		free_hooks(&fdf->events);
		terminate(EXIT, 0);
	}
	terminate(gen_error_msg(ERR, MACROS), 1);
}

/* this function takes a void *param, which is our *fdf.
it then runs destroy with -1 (a placeholder value so that destroy
can be initalized from this function as well as the hook) and
our *fdf, and returns 0 for the mlx hooking function to know
that the function x_close_win has been handled.
*/
int	x_close_win(void *param)
{
	destroy(-1, param);
	return (0);
}
