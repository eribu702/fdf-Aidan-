/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:36 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:26:39 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*gen_error_msg(char *s1, char *s2)
{
	char	*tmp;
	char	*error_msg;

	tmp = ft_strjoin(s1, "\n");
	error_msg = ft_strjoin(tmp, s2);
	ft_free(&tmp);
	return (error_msg);
}

void	terminate(char *message, short error)
{
	ft_printf("%s\n", message);
	if (error)
		ft_free(&message);
	exit(EXIT_SUCCESS);
}

/*
 * 	[TODO]	Init Img data to open x-window from terminal.. [X]
 * 	[TODO]	Draw some pixels to the screen with some colour. [X]
 * 	[TODO]	Draw a line with linear gradient. [X]
 * 	-	Parse FDF Struct into draw function to write pixels to the mlx img.
 * 	-	MLX Hook for event calls & MLX Loop for pixel output.
 */
int	main(int ac, char **av)
{
	t_map	map;
	t_fdf	fdf;

	if (ac == 2)
	{
		if (!init(av[1], &map, &fdf))
			terminate(gen_error_msg(ERR_MSG, INIT), 1);
		load_event_hooks(&fdf);
		render_fdf(&fdf);
		mlx_loop(fdf.mlx);
	}
	terminate(gen_error_msg(ERR_MSG, USAGE_ARG), 1);
}
