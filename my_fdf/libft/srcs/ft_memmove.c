/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:43:07 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:12 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				x;

	s = str2;
	d = str1;
	if (d < s)
	{
		x = 0;
		while (x < n)
		{
			d[x] = s[x];
			x++;
		}
	}
	else
	{
		x = n;
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (str1);
}
