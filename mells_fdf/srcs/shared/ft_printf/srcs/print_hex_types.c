/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:35:36 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:45:36 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_hex_len(unsigned long long value)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= 16;
		len += 1;
	}
	return (len);
}

int	do_convert(char *type, unsigned long int value, unsigned long long power)
{
	char				hex_c;
	int					ret;
	int					store;

	ret = 0;
	store = 0;
	while (power > 0)
	{
		store = value / power;
		if (ft_strchr("xp", *type))
			hex_c = "0123456789abcdef"[store];
		else if (*type == 'X')
			hex_c = "0123456789ABCDEF"[store];
		ret += print_char(hex_c);
		value = value % power;
		power /= 16;
	}
	return (ret);
}

int	convert_hex(char *type, unsigned long long value)
{
	int						ret;
	int						len;
	unsigned long long		power;

	ret = 0;
	power = 1;
	if (value == 0)
	{
		ret += print_char('0');
		return (ret);
	}
	len = get_hex_len(value);
	while (len > 1)
	{
		power *= 16;
		len--;
	}
	ret += do_convert(type, value, power);
	return (ret);
}

int	print_pointer(char *type, unsigned long long value)
{
	int	ret;

	ret = 0;
	ret += print_sign(type);
	ret += convert_hex(type, value);
	return (ret);
}

int	print_hex_types(char *type, va_list *arg_p)
{
	int	ret;

	ret = 0;
	if (ft_strchr("xX", *type))
		ret += convert_hex(type, va_arg(*arg_p, unsigned int));
	else if (*type == 'p')
		ret += print_pointer(type, (unsigned long long)va_arg(*arg_p, void *));
	return (ret);
}
