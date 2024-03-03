/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:17 by lmells            #+#    #+#             */
/*   Updated: 2022/01/05 09:35:05 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay_c;
	char	*ned_c;
	size_t	ned_len;

	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	hay_c = (char *)haystack;
	ned_c = (char *)needle;
	ned_len = ft_strlen(ned_c);
	if (ned_len == 0)
		return ((char *)hay_c);
	if (ned_len > (unsigned int)ft_strlen(hay_c))
		return (NULL);
	while (*hay_c && len--)
	{
		if (len + 1 < ned_len)
			break ;
		if ((*hay_c == *ned_c) && (ft_strncmp(hay_c, ned_c, ned_len) == 0))
			return ((char *)hay_c);
		hay_c++;
	}
	return (NULL);
}
