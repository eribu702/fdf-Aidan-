/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:35:35 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:35:35 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_char_types(char *type, va_list *arg_p)
{
	int	ret;

	ret = 0;
	if (ft_strchr("sc", *type))
	{
		if (*type == 'c')
			ret += print_char(va_arg(*arg_p, int));
		else if (*type == 's')
			ret += print_str(va_arg(*arg_p, char *));
	}
	return (ret);
}
