/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:38:37 by lmells            #+#    #+#             */
/*   Updated: 2022/02/15 09:38:37 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, int bytes)
{
	int		i;
	int		j;
	char	*output;

	if (s2 == NULL)
		return (NULL);
	output = (char *)malloc((ft_strlen(s1) + bytes + 1) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while ((s2 && s2[j]) && j < bytes)
		output[i++] = s2[j++];
	output[i] = '\0';
	return (output);
}
