/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:34:22 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:34:22 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*verify_type(const char **format)
{
	char	ch_p;

	(*format)++;
	ch_p = (char)**format;
	return (ft_strchr("csdiupxX%", ch_p));
}

int	convert_type(const char **format, char *type, va_list *arg_p)
{
	int	ret;

	ret = 0;
	if (ft_strchr("sc", *type))
		ret += print_char_types(type, arg_p);
	else if (ft_strchr("diu", *type))
		ret += print_nbr_types(type, arg_p);
	else if (ft_strchr("pxX", *type))
		ret += print_hex_types(type, arg_p);
	else if (*type == '%')
		ret += print_percent(type);
	(*format)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	char	*type;
	va_list	arg_p;

	len = 0;
	type = 0;
	if (!format)
		return (0);
	va_start(arg_p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			type = verify_type(&format);
			len += convert_type(&format, type, &arg_p);
		}
		else
		{
			write(1, format++, 1);
			len += 1;
		}
	}
	va_end(arg_p);
	return (len);
}
