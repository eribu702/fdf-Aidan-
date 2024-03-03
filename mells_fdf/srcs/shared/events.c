/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:32:37 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_default(int key_press, t_fdf *fdf)
{
	if (key_press == MAC_R || key_press == LI_R)
		fdf->camera = new_camera(fdf->map);
}

void	update_zoom(int key_press, t_fdf *fdf)
{
	if (key_press == MAC_MINUS || key_press == LI_MINUS)
	{
		if (fdf->camera.zoom > 0)
			fdf->camera.zoom -= 0.5;
	}
	else if (key_press == MAC_PLUS || key_press == LI_PLUS)
	{
		if (fdf->camera.zoom < INT_MAX)
			fdf->camera.zoom += 0.5;
	}
}

void	pan_movement(int key_press, t_fdf *fdf)
{
	if (key_press == MAC_ARROW_U || key_press == LI_ARROW_U)
		fdf->camera.off_y += 10;
	else if (key_press == MAC_ARROW_L || key_press == LI_ARROW_L)
		fdf->camera.off_x += 10;
	else if (key_press == MAC_ARROW_D || key_press == LI_ARROW_D)
		fdf->camera.off_y -= 10;
	else if (key_press == MAC_ARROW_R || key_press == LI_ARROW_R)
		fdf->camera.off_x -= 10;
}

void	update_rot(int key_press, t_fdf *fdf)
{
	if (key_press == MAC_W || key_press == LI_W)
		fdf->camera.rot_x -= 0.05;
	else if (key_press == MAC_S || key_press == LI_S)
		fdf->camera.rot_x += 0.05;
	else if (key_press == MAC_A || key_press == LI_A)
		fdf->camera.rot_y -= 0.05;
	else if (key_press == MAC_D || key_press == LI_D)
		fdf->camera.rot_y += 0.05;
	else if (key_press == MAC_E || key_press == LI_E)
		fdf->camera.rot_z -= 0.05;
	else if (key_press == MAC_Q || key_press == LI_Q)
		fdf->camera.rot_z += 0.05;
}

void	change_projection(int key_press, t_fdf *fdf)
{
	if (key_press == MAC_P || key_press == LI_P)
	{
		if (fdf->camera.iso)
			fdf->camera.iso = 0;
		else
			fdf->camera.iso = 1;
	}
	else if (key_press == MAC_I || key_press == LI_I)
	{
		if (fdf->camera.flat > 0)
			fdf->camera.flat -= 0.2;
	}
	else if (key_press == MAC_O || key_press == LI_O)
	{
		if (fdf->camera.flat < 10)
			fdf->camera.flat += 0.2;
	}
}
