/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2023/10/31 10:48:19 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * 	Uses file from args to gather & initialise all map data used for fdf.
 * 		File was validated previously, store char pointer in struct for
 * 		later use. Saves parsing another argument when unneccessary.
 * 		If parse_map function fails. Generate error message and parse
 * 		it to terminate function for exit. - Parse map function gathers and
 * 		stores all required map data.
 * 		Convert the list into seperate "altitude" & "colour" arrays.
 * 		Free the list - Will have no further use.
 */
static bool	init_map(char *file, t_map *map)
{
	t_stack	*data;

	if (file)
	{
		data = NULL;
		map->file = file;
		map->z_max = 0;
		map->z_min = 0;
		map->z_range = 0;
		if (!parse_map(map, &data))
			terminate(gen_error_msg(ERR_MSG, READ_MAP), 1);
		stack_to_arrays(data, &map);
		free_stack(&data);
		return (true);
	}
	return (false);
}

t_img	create_new_image(void *mlx)
{
	t_img	img;

	img.bits_per_pix = 0;
	img.vec_len = 0;
	img.endian = 0;
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pix, &img.vec_len,
			&img.endian);
	return (img);
}

t_camera	new_camera(t_map *map)
{
	t_camera	new;

	new.zoom = max_val(((WIDTH - MENU_W) / map->width / 2),
			(HEIGHT / map->height / 2));
	new.off_x = 0;
	new.off_y = 0;
	new.flat = 1;
	new.iso = 1;
	new.rot_x = 0;
	new.rot_y = 0;
	new.rot_z = 0;
	return (new);
}

static bool	init_fdf(t_map *map, t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (false);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT,
			"FDF 3D Wireframe Viewer");
	fdf->img = create_new_image(fdf->mlx);
	fdf->camera = new_camera(map);
	fdf->map = map;
	return (true);
}

/*
 * 	Initialise all required fdf data used to draw map.
 * 		Checks file and is of ".fdf" suffix - Type of file to read.
 * 		Initialises Map data from '*.fdf' file.
 * 		Initialises FDF Struct data - MlX values.
 */
bool	init(char *file, t_map *map, t_fdf *fdf)
{
	if (!check_file(file))
		terminate(gen_error_msg(ERR_MSG, USAGE_MAP), 1);
	if (!init_map(file, map))
		return (false);
	if (!init_fdf(map, fdf))
		return (false);
	return (true);
}
