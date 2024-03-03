/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:18:38 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 16:08:37 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag(va_list	args, const char str, int *i)
{
	int		len;

	len = 0;
	if (str == 'c')
		pf_putchar(va_arg(args, int), &len);
	else if (str == 's')
		pf_putstr(va_arg(args, char *), &len);
	else if (str == '%')
		pf_putchar('%', &len);
	else if (str == 'i' || str == 'd')
		pf_putnbr(va_arg(args, int), &len);
	else if (str == 'u')
		pf_unint(va_arg(args, unsigned int), &len);
	else if (str == 'x')
		pf_hex(va_arg(args, unsigned int), &len, 'x');
	else if (str == 'X')
		pf_hex(va_arg(args, unsigned int), &len, 'X');
	else if (str == 'p')
		pf_point(va_arg(args, size_t), &len);
	else
		return (len);
	(*i)++;
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_flag(args, str[++i], &i);
		}
		else
		{
			pf_putchar(str[i++], &len);
		}
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	char	c;

	c = 'a';
	ft_printf("%c\n", c);
	return (0);
}

%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
*/
