/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:41:33 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_text
{
	int			x;
	int			y;
	char		*str;
	bool		flag;
}	t_text;

static t_text	new_text(int x, int y, char *str, bool flag)
{
	t_text	text;

	text.x = x;
	text.y = y;
	text.str = str;
	text.flag = flag;
	return (text);
}

static void	add_text(t_fdf *fdf, t_text text)
{
	mlx_string_put(fdf->mlx, fdf->win, text.x, text.y, TEXT, text.str);
	if (text.flag)
		free(text.str);
}

static void	finish_info(t_fdf *fdf, int y)
{
	add_text(fdf, new_text(15, y += 25, "Zoom:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.zoom, 2), true));
	add_text(fdf, new_text(15, y += 25, "Point Height:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.flat, 2), true));
	add_text(fdf, new_text(15, y += 25, "Offset X:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.off_x, 3), true));
	add_text(fdf, new_text(15, y += 25, "Offset Y:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.off_y, 3), true));
	add_text(fdf, new_text(15, y += 25, "Rotate X:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.rot_x, 3), true));
	add_text(fdf, new_text(15, y += 25, "Rotate Y:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.rot_y, 3), true));
	add_text(fdf, new_text(15, y += 25, "Rotate Z:", false));
	add_text(fdf, new_text(160, y, float_to_array(fdf->camera.rot_z, 3), true));
}

void	print_menu_text(t_fdf *fdf)
{
	int	y;

	y = 15;
	add_text(fdf, new_text(80, y += 25, "Controls:", false));
	add_text(fdf, new_text(80, y += 25, "Zoom: +/-", false));
	add_text(fdf, new_text(50, y += 25, "Pan: Arrow Keys", false));
	add_text(fdf, new_text(40, y += 25, "Raise Points: O/I", false));
	add_text(fdf, new_text(60, y += 25, "Rotate X: W/S", false));
	add_text(fdf, new_text(60, y += 25, "Rotate Y: A/D", false));
	add_text(fdf, new_text(60, y += 25, "Rotate Z: Q/E", false));
	add_text(fdf, new_text(85, y += 25, "Reset: R", false));
	add_text(fdf, new_text(30, y += 25, "Toggle Isometric: P", false));
	add_text(fdf, new_text(25, y += 70, "Current Information:", false));
	add_text(fdf, new_text(15, y += 25,
			ft_strjoin("Map: ", fdf->map->file + 10), true));
	if (fdf->camera.iso)
		add_text(fdf, new_text(15, y += 25, "Projection: Isometric", false));
	else
		add_text(fdf, new_text(15, y += 25, "Projection: Parallel", false));
	finish_info(fdf, y);
}
