/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:45:33 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:14 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	x;

	x = 0;
	while (str1[x] && str1[x] == str2[x] && x < n)
		x++;
	if (x < n)
		return ((unsigned char) str1[x] - (unsigned char) str2[x]);
	return (0);
}
