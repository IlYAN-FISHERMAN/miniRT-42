/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:51:06 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:32:16 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINKED_LIST_H
# define FT_LINKED_LIST_H

//	includes
# include "ft_garbage_collector.h"

//	t_list: A linked list node
typedef struct s_list

{
	void				*content;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

//	ft_lstnew_back: Directly adds a new content at the back of the list
//	@param lst The list to add the new node to
//	@param content The content of the new node
//	@return The new list
t_list		*ft_lstnew_back(t_list *lst, void *content);
//	ft_lstnew_front: Directly adds a new content at the front of the list
//	@param lst The list to add the new node to
//	@param content The content of the new node
//	@return The new list
t_list		*ft_lstnew_front(t_list *lst, void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstget(t_list *lst, size_t idx);
int			ft_lstgetid(t_list *list, t_list *node);
void		*ft_lstpop(t_list **lst);
void		*ft_lstshift(t_list **lst);
t_list		*ft_lstrevrotate(t_list *lst);
t_list		*ft_lstrotate(t_list *lst);
t_list		*ft_lstswap(t_list *lst);
int			ft_lstremove(t_list **lst, void *content, void (*del)(void *));

#endif