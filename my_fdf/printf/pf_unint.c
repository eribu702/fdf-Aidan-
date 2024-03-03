/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:39:22 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 16:05:13 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_unint(unsigned int nbr, int *len)
{
	if (nbr >= 10)
		pf_unint(nbr / 10, len);
	pf_putchar(nbr % 10 + '0', len);
}
