/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:30 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:13 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	x;
	size_t	len;

	len = ft_strlen(str);
	x = 0;
	while (x <= len)
	{
		if (str[x] == (char)c)
			return ((char *)&str[x]);
		x++;
	}
	return (NULL);
}
