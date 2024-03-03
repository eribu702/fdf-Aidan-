/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:35:36 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:35:56 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_percent(char *type)
{
	int	ret;

	ret = 0;
	if (*type == '%')
		ret += print_char(*type);
	return (ret);
}

int	print_sign(char *type)
{
	int	ret;

	ret = 0;
	if (*type == 'p')
		ret += print_str("0x");
	return (ret);
}
