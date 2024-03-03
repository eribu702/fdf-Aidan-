/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:45:43 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:15 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!little[x])
		return ((char *)big);
	while (big[x] && x < n)
	{
		y = 0;
		if (big[x] == little[y])
		{
			while (big[x + y] == little [y] && (x + y) < n)
			{
				if (little[y + 1] == '\0')
					return ((char *)&big[x]);
				y++;
			}
		}
		x++;
	}
	return (NULL);
}
