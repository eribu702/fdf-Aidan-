/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:46:04 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:15 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	x;
	size_t	l;

	if (start > ft_strlen(s))
		l = 0;
	else
		l = ft_strlen(&s[start]);
	if (l < len)
			len = l;
	x = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (x < len)
	{
		sub[x] = s[start + x];
		x++;
	}
	sub[x] = 0;
	return (sub);
}
