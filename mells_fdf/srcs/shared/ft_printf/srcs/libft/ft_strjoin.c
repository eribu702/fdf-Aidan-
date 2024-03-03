/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:17 by lmells            #+#    #+#             */
/*   Updated: 2021/11/02 08:48:17 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
		if (!join)
			return (NULL);
		i = -1;
		while (s1[++i])
			join[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			join[len1] = s2[i];
			len1++;
		}
		join[len1] = '\0';
		return (join);
	}
	return (NULL);
}
