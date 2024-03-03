/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:18:28 by aroberts          #+#    #+#             */
/*   Updated: 2023/11/14 15:38:37 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* this code is likely temporary. i use it to draw images.
here we are using "my_draw()", which takes the image, a couple
structs to determine width and length, and width and length away
from the border as "offset", and an argb value. we use
another function called "int_to_argb()" that takes and interger
and converts it into an argb struc that our draw can understand.
*/
void	runner(t_img img)
{
	draw_quad(img, (t_point){200, 200}, (t_point){400, 400},
		int_to_argb(0x964B00));
	return ;
}
//#964B00 for brownint_to_argb(0x964B00)
//#87CEEB sky blue
/*
*/