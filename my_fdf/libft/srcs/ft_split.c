/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:44:23 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:13 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	words(char const *s, char delim)
{
	size_t	x;
	size_t	count;
	char	found;

	x = 0;
	count = 0;
	found = 1;
	while (s[x])
	{
		if (found && s[x] != delim)
		{
			found = 0;
			count++;
		}
		else if (!found && s[x] == delim)
			found = 1;
		x++;
	}
	return (count);
}

static char	*fillstring(char const**ss, char c)
{
	char	*str;
	size_t	x;

	x = 0;
	while (**ss && **ss == c)
		(*ss)++;
	while ((*ss)[x] && (*ss)[x] != c)
		x++;
	str = ft_calloc(x + 1, sizeof(char *));
	if (!str)
		return (NULL);
	ft_memcpy(str, *ss, x);
	*ss += x;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t			x;
	char			**strings;
	unsigned int	count;

	x = 0;
	if (!s)
		return (NULL);
	count = words(s, c);
	strings = ft_calloc(count + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	while (x < count)
	{
		strings[x] = fillstring(&s, c);
		if (!strings[x])
			return (NULL);
		x++;
	}
	strings[x] = NULL;
	return (strings);
}
