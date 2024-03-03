/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:45:01 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:14 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srcl;
	size_t	dstl;
	size_t	x;
	size_t	y;

	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	x = 0;
	y = dstl;
	if (dstl < size - 1 && size > 0)
	{
		while (src[x] && dstl + x < size - 1)
		{
			dst[y] = src[x];
			x++;
			y++;
		}
		dst[y] = 0;
	}
	if (dstl >= size)
		dstl = size;
	return (dstl + srcl);
}
