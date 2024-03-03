/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:38:31 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:38:31 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n_bytes)
{
	int		i;
	char	*dup;

	dup = NULL;
	if (!str || n_bytes <= 0)
		return (NULL);
	dup = (char *)ft_calloc(n_bytes + 1, sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && i < n_bytes)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
