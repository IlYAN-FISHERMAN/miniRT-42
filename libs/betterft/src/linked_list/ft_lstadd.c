/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:12:24 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 16:38:54 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *)galloc(sizeof(t_list));
	if (!p)
		return (0);
	p->content = content;
	p->next = 0;
	p->prev = 0;
	return (p);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

t_list	*ft_lstnew_back(t_list *lst, void *content)
{
	t_list	*newlist;

	newlist = ft_lstnew(content);
	if (!newlist)
		return (0);
	ft_lstadd_back(&lst, newlist);
	return (lst);
}

t_list	*ft_lstnew_front(t_list *lst, void *content)
{
	t_list	*newlist;

	newlist = ft_lstnew(content);
	if (!newlist)
		return (0);
	ft_lstadd_front(&lst, newlist);
	return (lst);
}
