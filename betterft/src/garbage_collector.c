/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:13 by rude-jes          #+#    #+#             */
/*   Updated: 2024/05/10 03:12:38 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../betterft.h"

t_garbcol	**getgarbage(void)
{
	static t_garbcol	*collector;

	return (&collector);
}

void	*addgarbage(void *address)
{
	t_garbcol	**collector;
	t_garbcol	*tmp;

	if (!address)
		return (0);
	if (!GARBAGE_COLLECTOR)
		return (address);
	collector = getgarbage();
	tmp = (t_garbcol *)malloc(sizeof(t_garbcol));
	if (!tmp)
		return (0);
	if (*collector)
		tmp->next = (*collector);
	else
		tmp->next = 0;
	tmp->content = address;
	*collector = tmp;
	return (address);
}
