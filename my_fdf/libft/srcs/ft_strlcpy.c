/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:45:09 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:14 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	x = 0;
	if (!size)
		return (ft_strlen(src));
	if (size > 0)
	{
		while (x < (size - 1) && src[x])
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (ft_strlen(src));
}
