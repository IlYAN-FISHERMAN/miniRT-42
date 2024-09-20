/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:03:12 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:25:32 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list	*ft_lstrotate(t_list *lst)
{
	t_list	*tmp;

	if (ft_lstsize(lst) < 2)
		return (lst);
	tmp = lst;
	lst = lst->next;
	ft_lstlast(lst)->next = tmp;
	tmp->next = 0;
	return (lst);
}

t_list	*ft_lstswap(t_list *lst)
{
	void	*swap;

	if (ft_lstsize(lst) < 2)
		return (lst);
	swap = lst->content;
	lst->content = lst->next->content;
	lst->next->content = swap;
	return (lst);
}

t_list	*ft_lstrevrotate(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize(lst);
	if (size < 2)
		return (lst);
	tmp = ft_lstget(lst, size - 2);
	ft_lstadd_front(&lst, ft_lstlast(lst));
	tmp->next = 0;
	return (lst);
}
