/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:41:08 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:49:48 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	final;
	int	neg;
	int	x;

	final = 0;
	neg = 0;
	x = 0;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			neg = 1;
		x++;
	}
	while (ft_isdigit(str[x]))
	{
		final = final * 10 + (str[x] - '0');
		x++;
	}
	if (neg)
		return (-final);
	return (final);
}
