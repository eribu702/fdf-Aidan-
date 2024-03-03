/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:38 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:13 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	size_t	x;
	size_t	byt;
	char	*dest;

	x = 0;
	byt = (ft_strlen(str) + 1) * sizeof(char);
	dest = malloc(byt);
	if (!dest)
		return (NULL);
	while (str[x])
	{
		dest[x] = str[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}
