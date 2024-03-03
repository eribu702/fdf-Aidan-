/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:19:36 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 16:04:43 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nbr < 0)
	{
		pf_putchar('-', len);
		pf_putnbr(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			pf_putnbr(nbr / 10, len);
		pf_putchar(nbr % 10 + '0', len);
	}
}
