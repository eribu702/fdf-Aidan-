/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:48:16 by lmells            #+#    #+#             */
/*   Updated: 2021/11/02 08:48:16 by lmells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*prev_list;
	t_list	*next_list;

	if (!lst || !(*f))
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (NULL);
	next_list = new_list;
	prev_list = lst->next;
	while (1)
	{
		if (prev_list == NULL)
			break ;
		next_list->next = ft_lstnew((*f)(prev_list->content));
		if (!next_list)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		prev_list = prev_list->next;
		next_list = next_list->next;
	}
	return (new_list);
}
