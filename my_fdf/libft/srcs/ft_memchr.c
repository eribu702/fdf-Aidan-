/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:42:34 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:11 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)str)[x] == (unsigned char)c)
			return ((void *)str + x);
		x++;
	}
	return (NULL);
}
