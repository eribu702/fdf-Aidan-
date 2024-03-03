/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:03:49 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/10 16:07:41 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
pixel_put takes our image addr, a pixel coord (t-point v) and an int,
called colour. first it creates a char addr, and has it point to 
img->addr, this lets us alter global variables from inside our function,
but not before adding that to v.y, times by ll, + v.x * (bpp/8). now i dont
completely understand that, but it bassicly set addr to the address described
by t_point v, but with our ll and bpp, which lets it store the information
of each pixel in a much more condensed fashion. Then we type cast addr to an
unsigned int, and set it to colour. this effectively changes the colour of a 
single pixel.
*/
void	pixel_put(t_img *img, t_point v, int colour)
{
	char	*addr;

	if (v.x >= WIDTH || v.y >= HEIGHT)
		return ;
	addr = img->addr + (v.y * img->ll + v.x * (img->bpp / 8));
	*(unsigned int *)addr = colour;
}

/*
this function takes an t_argb struct called argb. this is a struct that
contains 4 ints. an int for alpha, red, green and blue respectively.
we are going to condense these 4 values into one int. since this function
returns and int, we can write 'return', and begin to list the parts of
our return value. we use the '|' operator to combine the parts,
and we use bit shifting to format this correctly.
for example, if argb.a and argb.b were full, and the others are empty,
we want something like this 0xFF0000FF.
so when we do argb.a, we bit shift 24 bits, to fill in these F's.
0xFF000000
*/
int	argb_to_int(t_argb argb)
{
	return (argb.a << 24 | argb.r << 16 | argb.g << 8 | argb.b);
}

/*
here we use an int colour (this int would be an 8 digit int)
and set up a argb struct. we then set each struct variable to
different parts of the 'colour' int, to do this we use bit shifting.
we then use & 0xFF to format whatever number is left into a hex value.
example, on the line argb.r = (colour >> 16) & 0xFF;
it would look more like this
argb.red = (colour(12345678) >> 16) = colour(345678) & 0xFF =
0x34.
here we used bit shifting (>>) to move the digits back, and put the 3
at the front of the interger, and then (&) to format, all other variables
get removed. if we formatted with (& 0xFFFF) though for example, the
result would look like this =
0x3456.
no bit shifting is required for 
*/
t_argb	int_to_argb(int colour)
{
	t_argb	argb;

	argb.a = (colour >> 24) & 0xFF;
	argb.r = (colour >> 16) & 0xFF;
	argb.g = (colour >> 8) & 0xFF;
	argb.b = colour & 0xFF;
	return (argb);
}

/* inverts the colour of its input */
t_argb	get_opposite(int colour)
{
	t_argb	s;

	s = int_to_argb(colour);
	s.r = 255 - s.r;
	s.g = 255 - s.g;
	s.b = 255 - s.b;
	return (s);
}
