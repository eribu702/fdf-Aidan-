/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:53 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:14 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	ls1;
	size_t	ls2;
	size_t	x;

	x = 0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	concat = (char *)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!concat)
		return (NULL);
	while (x < ls1)
	{
		concat[x] = s1[x];
		x++;
	}
	while (x < ls2 + ls1)
	{	
		concat[x] = s2[x - ls1];
		x++;
	}
	concat[x] = 0;
	return (concat);
}
