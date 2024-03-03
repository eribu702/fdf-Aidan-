/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:07:00 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/20 13:00:45 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../libft.h"

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
