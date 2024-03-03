/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:16:51 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/15 14:16:56 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../libft.h"

int ft_strchr_flag(const char *str, int c, int flag)
{
	int	i;

	if (!str && flag == 1)
		return (-5);
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
