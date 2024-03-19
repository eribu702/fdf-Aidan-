/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:49:47 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/19 14:40:46 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*this generates our error message based on a different char
initalized in our msgs.h. there are two chars, one is set to
a temporary char, given a new line at the end, and then both are
combined on the char *error_msg, the tempporary's memory is free
and then the final message is returned.
*/
char	*gen_error_msg(char *s1, char *s2)
{
	char	*tmp;
	char	*error_msg;

	tmp = ft_strjoin(s1, "\n");
	error_msg = ft_strjoin(tmp, s2);
	ft_free(&tmp);
	return (error_msg);
}

/*This function exits our fdf, but first it prints a char *message,
this is normally used in conjunction with out gen_error_msg function, then
it frees the message memory and exits our fdf project.
*/
void	terminate(char *message, short error)
{
	ft_printf("%s\n", message);
	if (error)
		ft_free(&message);
	exit(EXIT_SUCCESS);
}

/*here we initalize our fdf struct and run it through our initialize function,
this will begin mlx, our hooking function, which looks after inputs to our fdf
project, our render function, which handles putting images to the screen, and
replacing or 'updating' the old ones with the new. and mlx_loop, that 'runs'
mlx rather than it being a static window.
 */
int	main(void)
{
	t_fdf	fdf;

	init(&fdf);
	load_event_hooks(&fdf);
	render_fdf(&fdf);
	mlx_loop(fdf.mlx);
}

/*
write comments for:

utils functinos x
READ MAP FUNCTIONS
MAP functions X
stack functions


and the uncommented functions you added to libft

have fun !!
in save line data(), your split() may be different


YOUR INIT_MAP() AND CHECK_FILE() ARE COMMENTED OUT, when you
start linking maps add these in and change your initilization. chow
*/