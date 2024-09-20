/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_galloc_secure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 02:54:30 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:06:49 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector_intern.h"

void	*galloc(size_t size)
{
	void	*address;
	int		old_errno;

	old_errno = errno;
	errno = 0;
	address = addgarbage(malloc(size));
	if (!address)
	{
		if (errno)
			ft_putendl_fd(strerror(errno), 2);
		else
			ft_putendl_fd("error: failed to allocate memory", 2);
		cleargarbage();
		if (errno)
			exit(errno);
		exit(1);
	}
	errno = old_errno;
	return (address);
}
