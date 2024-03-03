/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:16 by lmells            #+#    #+#             */
/*   Updated: 2021/11/02 08:48:16 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ternint(int condition, long val1, long val2)
{
	if (condition)
		return (val1);
	else
		return (val2);
}

static short	ft_is_negative(long n)
{
	if (n >= 0)
	{
		return (0);
	}
	else
		return (1);
}

static short	ft_digits(long n)
{
	short	n_dig;

	if (n == 0)
		n_dig = 1;
	else
		n_dig = 0;
	while (n != 0)
	{
		n_dig++;
		n /= 10;
	}
	return (n_dig);
}

char	*ft_itoa(int n)
{
	char		*nbr_str;
	short		n_dig;
	short		neg;
	long int	nbr;

	nbr = (long int)n;
	neg = ft_is_negative(nbr);
	n_dig = ft_digits(nbr) + ft_ternint(neg == 1, 1, 0);
	nbr_str = (char *)malloc((n_dig + 1) * sizeof(char));
	if (!nbr_str)
		return (NULL);
	nbr_str[0] = '0';
	nbr_str[n_dig] = 0;
	if (neg)
	{
		nbr_str[0] = '-';
		nbr = -nbr;
	}
	while (nbr && --n_dig >= 0)
	{
		nbr_str[n_dig] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (nbr_str);
}
