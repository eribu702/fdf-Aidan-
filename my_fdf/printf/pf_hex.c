/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:13:17 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 16:03:54 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_hex(unsigned int nbr, int *len, int XX)
{
	char	str[25];
	char	*base;
	int		i;

	if (XX == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (nbr == 0)
	{
		pf_putchar('0', len);
		return ;
	}
	while (nbr != 0)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	while (i--)
		pf_putchar(str[i], len);
	return ;
}
