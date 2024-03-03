/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_component.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:39:16 by lmells            #+#    #+#             */
/*   Updated: 2022/03/01 15:48:45 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*trim_component(char *component, int c)
{
	int		size;

	size = 0;
	if (component[size] == c)
		return (NULL);
	while (component[size] != '\0')
	{
		if (component[size] == c)
			break ;
		size++;
	}
	if (size == 0)
		return (NULL);
	return (ft_strndup(component, size));
}
