/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_component.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:57:59 by aroberts          #+#    #+#             */
/*   Updated: 2024/02/20 14:58:26 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../libft.h"

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
