/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:41:52 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_abs(int x)
{
	if (x < 0)
		return (-(x));
	return (x);
}

t_point	get_absolute(t_point *s, t_point *f)
{
	t_point	abs;

	abs.x = get_abs(f->x - s->x);
	abs.y = get_abs(f->y - s->y);
	return (abs);
}

t_point	get_sign(t_point *s, t_point *f)
{
	t_point	sign;

	sign.x = -1;
	sign.y = -1;
	if (s->x < f->x)
		sign.x = 1;
	if (s->y < f->y)
		sign.y = 1;
	return (sign);
}

static int	get_index(int x, int y, int w)
{
	return (y * w + x);
}

t_point	set_point(int x, int y, t_fdf *fdf)
{
	int		i;
	t_point	point;

	i = get_index(x, y, fdf->map->width);
	point.x = x;
	point.y = y;
	point.z = fdf->map->altitude[i];
	if (fdf->map->colours[i] == -1)
		point.colour = set_default_colour_scheme(fdf->map, &point.z);
	else
		point.colour = int_to_argb(fdf->map->colours[i]);
	return (point);
}
