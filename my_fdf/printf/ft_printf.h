/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:23:29 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 16:38:58 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	pf_putstr(char *args, int *length);
void	pf_putnbr(int nbr, int *len);
void	pf_putchar(char c, int *len);
void	pf_unint(unsigned int nbr, int *len);
void	pf_hex(unsigned int nbr, int *len, int XX);
void	pf_point(size_t point, int *len);

#endif