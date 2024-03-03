/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:16 by lmells            #+#    #+#             */
/*   Updated: 2021/11/02 08:48:16 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*free_elem;

	if (!lst)
		return ;
	elem = *lst;
	while (elem)
	{
		free_elem = elem;
		elem = elem->next;
		ft_lstdelone(free_elem, del);
	}
	*lst = NULL;
}
