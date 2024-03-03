/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:45:57 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:15 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	match(char c, const char *set)
{
	size_t	x;

	x = 0;
	while (set[x])
	{
		if (set[x] == c)
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	x;	
	char	*result;

	x = 0;
	end = ft_strlen(s1);
	start = 0;
	if (!(s1 || set))
		return ((char *)s1);
	while (s1[start] && match(s1[start], set))
		start++;
	while (end > start && match(s1[end - 1], set))
		end--;
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (start < end)
		result[x++] = s1[start++];
	result[x] = 0;
	return (result);
}
