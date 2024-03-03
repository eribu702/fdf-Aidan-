/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:42:18 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_map(t_point *p, t_fdf *fdf)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->height / 2;
	p->z -= fdf->map->z_range / 2;
}

void	isometric(t_point *p, t_camera *camera)
{
	t_point	prev;

	if (!camera->iso)
		return ;
	prev.x = p->x;
	prev.y = p->y;
	p->x = (prev.x - prev.y) * cos(degrees_to_radian(30));
	p->y = -p->z + (prev.x + prev.y) * sin(degrees_to_radian(30));
}

static t_point	center_offset(t_point p, t_fdf *fdf)
{
	p.x += (((WIDTH + MENU_W) / 2) + fdf->camera.off_x);
	p.y += ((HEIGHT / 2) + fdf->camera.off_y);
	return (p);
}

/*
 *	-	Apply Zoom
 *	-	Apply Rotation
 *	-	Draw Isometric Projection, if mode on
 *	-	Apply Offset for center and pan movement.
 */
t_point	project(t_point p, t_fdf *fdf)
{
	normalize_map(&p, fdf);
	p.x *= fdf->camera.zoom;
	p.y *= fdf->camera.zoom;
	p.z *= (fdf->camera.zoom / 10) * fdf->camera.flat;
	rotate_3d(&p, fdf);
	isometric(&p, &fdf->camera);
	return (center_offset(p, fdf));
}
