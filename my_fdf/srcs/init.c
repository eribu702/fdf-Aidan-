/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:15:20 by aroberts          #+#    #+#             */
/*   Updated: 2024/03/22 17:29:07 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
/*
here in our funciton init_map, it is a static bool, we use this
so we can give an error if something goes wrong, and also work out 
what the error is, so we can give the correct message to the user.
in our main, we initialize our fdf and map structs, and this function
takes our map struct and the 'file' being the map that was compiled
with fdf. we also initialize a stack struct called data. if there is
a file, we begin to fill in the data with
zeroes and a NULL. we set the file component to our 'file'.
this function is a static, so these changes will be saved and can be
used at any time. we then put the map and data structures into our parse map
function, if it returns false, we send an error message. otherwise, we then
send them through our stack_to_arrays function and then our free_stack
function.

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
		if (parse_map(map, &data))
			terminate(gen_error_msg(ERR, READ_MAP), 1);
		stack_to_arrays(data, &map);
		free_stack(&data);
		return (true);
	}
	return (false);
}

here we initalize an img struct and set some of the variables within it.
we then use a couple mlx functions to 'create an image', which at the
moment is blank, but a blank slate we can draw on.
we then return (img).
*/

t_img	create_new_image(void *mlx)
{
	t_img	img;

	img.bpp = 0;
	img.ll = 0;
	img.endian = 0;
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll,
			&img.endian);
	return (img);
}

/* init_fdf is a static bool meaning it is called once and retains itself so it
can be altered each time. we use the mlx function mlx_init to begin or
initalize fdf,
with the mlx project. if mlx doesnt work, we return false, otherwise we continue
to make a new window, name it "fdf", and run our create_new_image() function.
if it reaches the return (true); then it has worked.
*/
static bool	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (false);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->img = create_new_image(fdf->mlx);
	return (true);
}

/* our init function is a bool, so it returns true or false, 
and it passes fdf through another function called init_fdf.
*/
bool	init(t_fdf *fdf)
{
	if (!init_fdf(fdf))
		return (false);
	return (true);
}
