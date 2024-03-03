/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:44:28 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
 *	3D Matrix Rotation
 *
 *				Rotate X
 *		   ____         _____
 *		x1|  1     0      0  |
 *		y1|  0  cos(X) sin(X)|
 *		z1|  0 -sin(X) cos(X)|
 *		  |____          ____|
 */
static void	rotate_x(t_point *p, t_camera *camera)
{
	t_point	prev;

	prev = *p;
	p->y = (prev.y * cos(camera->rot_x)) + (prev.z * sin(camera->rot_x));
	p->z = (-prev.y * sin(camera->rot_x)) + (prev.z * cos(camera->rot_x));
}

/*
 *				Rotate Y
 *		  ____         _____
 *		x1|cos(Y)  0   sin(Y)|
 *		y2|  0     1      0  |
 *		z2|-sin(Y) 0   cos(Y)|
 *		  |____          ____|
 */
static void	rotate_y(t_point *p, t_camera *camera)
{
	t_point	prev;

	prev = *p;
	p->x = (prev.x * cos(camera->rot_y)) + (prev.z * sin(camera->rot_y));
	p->z = (-prev.x * sin(camera->rot_y)) + (prev.z * cos(camera->rot_y));
}

/*
 *				Rotate Z
 *		   ____         _____
 *		x1|cos(Z) -sin(Z)  0 |
 *		y1|sin(Z)  cos(Z)  0 |
 *		z1|  0      0      1 |
 *		  |____          ____|
 */
static void	rotate_z(t_point *p, t_camera *camera)
{
	t_point	prev;

	prev = *p;
	p->x = (prev.x * cos(camera->rot_z)) - (prev.y * sin(camera->rot_z));
	p->y = (prev.x * sin(camera->rot_z)) + (prev.y * cos(camera->rot_z));
}

void	rotate_3d(t_point *p, t_fdf *fdf)
{
	rotate_x(p, &fdf->camera);
	rotate_y(p, &fdf->camera);
	rotate_z(p, &fdf->camera);
}
