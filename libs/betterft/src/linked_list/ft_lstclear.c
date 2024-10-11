/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:12:18 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/08 10:07:14 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstreader;

	lstreader = *lst;
	while (*lst)
	{
		lstreader = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lstreader;
	}
	*lst = 0;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	gfree(lst);
}

void	*ft_lstpop(t_list **lst)
{
	t_list	*last;
	void	*content;

	last = ft_lstlast(*lst);
	if (last->prev)
		last->prev->next = 0;
	else
		*lst = 0;
	content = last->content;
	gfree(last);
	return (content);
}

void	*ft_lstshift(t_list **lst)
{
	t_list	*first;
	void	*content;

	first = *lst;
	if (first->next)
		first->next->prev = 0;
	*lst = first->next;
	content = first->content;
	gfree(first);
	return (content);
}
