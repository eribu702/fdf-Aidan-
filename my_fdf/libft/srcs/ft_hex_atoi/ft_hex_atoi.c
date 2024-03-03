/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:56:39 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/20 14:56:49 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../libft.h"

static int	is_hex(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

int	ft_hex_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	str = trim_component(str, '\n');
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (str[i])
	{
		res *= 16;
		res += is_hex(str[i]);
		i++;
	}
	return (res);
}
