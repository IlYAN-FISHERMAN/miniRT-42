/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:17:24 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/21 14:21:41 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_reallocf(void *ptr, size_t size, size_t newsize)
{
	unsigned char	*old_alloc;
	unsigned char	*new_alloc;
	size_t			i;

	if (size <= 0 || ptr == 0)
		return (galloc(newsize));
	old_alloc = (unsigned char *)ptr;
	new_alloc = (unsigned char *)galloc(newsize);
	if (new_alloc == 0)
	{
		gfree(ptr);
		return (0);
	}
	i = 0;
	while (i < size && i < newsize)
	{
		new_alloc[i] = old_alloc[i];
		i++;
	}
	gfree(ptr);
	return (new_alloc);
}

char	*ft_memtostr(void *mem, size_t size)
{
	char	eos;

	eos = '\0';
	mem = ft_reallocf(mem, size, size + 1);
	if (!mem)
		return (0);
	((unsigned char *)mem)[size] = eos;
	return ((char *)mem);
}
