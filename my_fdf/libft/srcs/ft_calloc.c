/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:41:27 by aroberts          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:10 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*dst;
	int		len;

	len = nitems * size;
	dst = malloc(len);
	if (!dst)
		return (NULL);
	ft_bzero(dst, len);
	return (dst);
}
