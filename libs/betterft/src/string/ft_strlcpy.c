/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:40:44 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:01:49 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(dst);
	if (dstsize <= size)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (i + size < dstsize - 1 && src[i])
	{
		dst[i + size] = src[i];
		i++;
	}
	dst[i + size] = 0;
	return (ft_strlen(src) + size);
}

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while ((unsigned int)j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
