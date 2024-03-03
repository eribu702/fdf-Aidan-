/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:37:17 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:46:45 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_decimals(char *dest, double nb, int decimal)
{
	int	i;

	i = 0;
	dest[i++] = '.';
	if (nb < 0)
		nb *= -1;
	while (i <= decimal)
	{
		nb *= 10;
		dest[i] = ((int)nb % 10) + '0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*float_to_array(double nb, int decimal)
{
	char	*array;
	char	*int_str;
	char	*dec_str;

	if (decimal <= 0)
		return (ft_itoa((int)nb));
	if (decimal > 7)
		decimal = 7;
	dec_str = (char *)malloc((decimal + 2) * sizeof(char));
	if (!dec_str)
		return (NULL);
	int_str = ft_itoa((int)nb);
	dec_str = get_decimals(dec_str, nb, decimal);
	array = ft_strjoin(int_str, dec_str);
	free(int_str);
	free(dec_str);
	return (array);
}
