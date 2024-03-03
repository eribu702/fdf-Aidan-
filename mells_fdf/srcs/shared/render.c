/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:42:56 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_bg(t_fdf *fdf)
{
	int		i;
	int		*screen;
	t_img	*img;

	img = &(fdf->img);
	ft_bzero(img->addr, WIDTH * HEIGHT * (img->bits_per_pix / 8));
	screen = (int *)(img->addr);
	i = 0;
	while (i < (WIDTH * HEIGHT))
	{
		screen[i] = set_bg_colour(i);
		i++;
	}
}

static bool	calc_vector(t_point *s, t_point *f, t_vector *line, int error[])
{
	if ((s->x < MENU_W && f->x < MENU_W) || (s->y < 0 && f->y < 0)
		|| (s->x >= WIDTH && f->x >= WIDTH)
		|| (s->y >= HEIGHT && f->y >= HEIGHT))
		return (false);
	line->delta = get_absolute(s, f);
	line->sign = get_sign(s, f);
	error[0] = line->delta.x - line->delta.y;
	return (true);
}

static void	draw_line(t_point s, t_point f, t_fdf *fdf)
{
	t_vector	line;
	t_point		curr;
	int			error[2];

	if (!calc_vector(&s, &f, &line, error))
		return ;
	curr = s;
	put_pixel(&fdf->img, f, argb_to_int(f.colour));
	while (curr.x != f.x || curr.y != f.y)
	{
		put_pixel(&fdf->img, curr, set_colour(curr, s, f, line.delta));
		error[1] = error[0] * 2;
		if (error[1] > -line.delta.y)
		{
			error[0] -= line.delta.y;
			curr.x += line.sign.x;
		}
		if (error[1] < line.delta.x)
		{
			error[0] += line.delta.x;
			curr.y += line.sign.y;
		}
	}
}

static void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	draw_bg(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				draw_line(project(set_point(x, y, fdf), fdf),
					project(set_point(x + 1, y, fdf), fdf), fdf);
			if (y + 1 < fdf->map->height)
				draw_line(project(set_point(x, y, fdf), fdf),
					project(set_point(x, y + 1, fdf), fdf), fdf);
			x++;
		}
		y++;
	}
}

void	render_fdf(t_fdf *fdf)
{
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img = create_new_image(fdf->mlx);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	print_menu_text(fdf);
}
