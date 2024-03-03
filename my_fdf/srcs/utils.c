/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:44:32 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/28 15:52:49 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
This bool sends true or false, if the int is valid, meaning
that it is not too high, and not too low, it will send true
otherwise, false.
*/
bool	valid_int(int nb)
{
	if (nb >= INT_MIN && nb <= INT_MAX)
		return (true);
	return (false);
}

/*
this bool takes in a char * named file_name. it declares two ints
and a char * with 5 bits of memory. i is set to 0 and used to set
check to = "0000'\0'". we set j to = (i - 1) (3).
and then we set i to strlen(file_name - 1). then, while
j >= 0, we set check[j] to file_name[i], and decrement.
this will set check to the last 4 characters of file_name.
we then use and if statement and strcmp() to compare check,
and the string ".fdf", if this is true, we return true, as
we now know the file_name file ends with .fdf . otherwise, false.
*/
/*
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
*/