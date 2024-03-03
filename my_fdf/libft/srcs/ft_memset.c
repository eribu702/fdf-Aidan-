/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:43:30 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:12 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s1;
	size_t			x;

	x = 0;
	s1 = str;
	while (x < n)
	{
		s1[x] = (unsigned char)c;
		x++;
	}
	return (str);
}
