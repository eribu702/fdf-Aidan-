/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:37:39 by lmells            #+#    #+#             */
/*   Updated: 2024/02/19 15:11:20 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

/*
 * 	Free's the split array and sets memory to NULL.
 * 		Loop through values of split array.
 * 		Send the address of the split value to free function.
 * 		Free split double pointer and set memory to NULL.
 */
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	*ft_malloc_fill(size_t count, size_t size)
{
	char	*array;
	size_t	i;
	size_t	bytes;

	bytes = count * size;
	array = (char *)malloc(bytes);
	if (!array)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		array[i] = '0';
		i++;
	}
	return (array);
}
