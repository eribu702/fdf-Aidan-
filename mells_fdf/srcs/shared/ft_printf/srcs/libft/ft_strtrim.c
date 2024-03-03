/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:17 by lmells            #+#    #+#             */
/*   Updated: 2021/11/02 08:48:17 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_is_char(char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_allocate_size(size_t *start, size_t *end)
{
	if (*end < *start)
		return (0);
	else
		return (*end - *start);
}

static long	ft_ternary_int(int condition, long val1, long val2)
{
	if (condition)
		return (val1);
	else
		return (val2);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	alloc_size;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_is_char(s1[start], set) == 1)
		start++;
	end = ft_strlen((char *)s1);
	while (end && ft_is_char(s1[ft_ternary_int(end == 0, end, end - 1)], set)
		== 1)
		end--;
	alloc_size = ft_allocate_size(&start, &end);
	trim = (char *)malloc((alloc_size + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
