/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:53:54 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:22:07 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list	*ft_lstget(t_list *lst, size_t idx)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (i < idx)
	{
		if (!lst->next)
			return (0);
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_lstgetid(t_list *list, t_list *node)
{
	int	i;

	if (!node || !list)
		return (-1);
	i = -1;
	while (i++, list && list != node)
		list = list->next;
	if (list)
		return (i);
	return (-1);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = -1;
	while (i++, lst)
		lst = (*lst).next;
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
