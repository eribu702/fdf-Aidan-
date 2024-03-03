/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:27:31 by aroberts          #+#    #+#             */
/*   Updated: 2023/11/14 15:37:34 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/* draw quad stands for draw quadilateral is a prettu rudimentaryn
function at this point, but it takes
our pixel put function that changes the argb value of a pixel, it takes in
a t_point (which holds both an x and a y value) for width and height purposes,
another t_point, so that we can offset these pixels (otherwise it would draw
from the top left corner until it reaches our set value) and an t_argb
with argb values. it creates a temporary t_point which is the sum of the
offset and the w&h values, it then uses 
*/
void	draw_quad(t_img img, t_point v, t_point offset, t_argb c)
{
	t_point	a;

	a.x = v.x + offset.x;
	while (a.x >= (offset.x))
	{
		a.y = v.y + offset.y;
		while (a.y >= (offset.y))
		{
			pixel_put(&img, a, argb_to_int(c));
			a.y--;
		}
		a.x--;
	}
	return ;
}

/* this function, draw backround, fist initializes a t_img, (img), and sets
fdf->img's data to equal itself. we then clear the memory of our screen to NULL.
now we can type cast this memory to type (int)'s so that each byte of data (the
pixels) can be incremented through and have their colour
set with set_bg_colour().
*/
static void	draw_bg(t_fdf *fdf)
{
	int		i;
	int		*screen;
	t_img	*img;

	img = &(fdf->img);
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bpp / 8));
	screen = (int *)(img->addr);
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		screen[i] = BG;
		i++;
	}
}

/* our render function checks if an image has been created, or exists.
if it does it destroys that image, creates a new one, runs our runner code,
and then prints or puts this new updated image to the window.
*/
void	render_fdf(t_fdf *fdf)
{
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img = create_new_image(fdf->mlx);
	draw_bg(fdf);
	runner(fdf->img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}
