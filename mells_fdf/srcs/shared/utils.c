/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:32:38 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:32:38 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_bg_colour(int index)
{
	if ((index % WIDTH) < MENU_W)
		return (MENU_BG);
	return (BG);
}

int	max_val(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

bool	valid_int(int nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (true);
	return (false);
}

bool	check_file(char *file_name)
{
	int		i;
	int		j;
	char	check[5];

	i = 0;
	while (i < 4)
	{
		check[i] = '0';
		i++;
	}
	check[i] = '\0';
	j = i - 1;
	i = ft_strlen(file_name) - 1;
	while (j >= 0)
	{
		check[j] = file_name[i];
		i--;
		j--;
	}
	if (!ft_strcmp(check, ".fdf"))
		return (true);
	return (false);
}
