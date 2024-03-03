/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:37 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:40:55 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calc_percentage(int s, int f, int c)
{
	double	percent;
	double	distance;
	double	placement;

	distance = f - s;
	placement = c - s;
	if (distance == 0)
		return (1.0);
	percent = placement / distance;
	return (percent);
}

/*
 *	M_1_PI >>> The recipricol of pi. (1/pi).
 */
double	degrees_to_radian(double degrees)
{
	return (degrees * (M_1_PI / 18));
}
