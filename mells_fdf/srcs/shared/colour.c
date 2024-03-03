/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:32:37 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *img, t_point v, int colour)
{
	char	*addr;

	if (v.x < MENU_W || v.y < 0 || v.x >= WIDTH || v.y >= HEIGHT)
		return ;
	addr = img->addr + (v.y * img->vec_len + v.x * (img->bits_per_pix / 8));
	*(unsigned int *)addr = colour;
}

int	argb_to_int(t_argb argb)
{
	return (argb.a << 24 | argb.r << 16 | argb.g << 8 | argb.b);
}

t_argb	int_to_argb(int colour)
{
	t_argb	argb;

	argb.a = (colour >> 24) & 0xFF;
	argb.r = (colour >> 16) & 0xFF;
	argb.g = (colour >> 8) & 0xFF;
	argb.b = colour & 0xFF;
	return (argb);
}

t_argb	set_default_colour_scheme(t_map *map, int *z)
{
	double	percent;

	percent = calc_percentage(map->z_min, map->z_max, *z);
	if (percent < 0.2)
		return (int_to_argb(0xEF629F));
	else if (percent < 0.4)
		return (int_to_argb(0xEF7DA0));
	else if (percent < 0.6)
		return (int_to_argb(0xEF96A1));
	else if (percent < 0.8)
		return (int_to_argb(0xEFAFA2));
	else
		return (int_to_argb(0xEECDA3));
}

int	set_colour(t_point curr, t_point s, t_point f, t_point delta)
{
	t_argb	grad;
	double	percent;

	if (argb_to_int(curr.colour) == argb_to_int(f.colour))
		return (argb_to_int(curr.colour));
	if (delta.x > delta.y)
		percent = calc_percentage(s.x, f.x, curr.x);
	else
		percent = calc_percentage(s.y, f.y, curr.y);
	grad.a = 0;
	grad.r = s.colour.r * (1 - percent) + f.colour.r * percent;
	grad.g = s.colour.g * (1 - percent) + f.colour.g * percent;
	grad.b = s.colour.b * (1 - percent) + f.colour.b * percent;
	return (argb_to_int(grad));
}
