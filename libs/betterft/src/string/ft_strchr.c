/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:42:45 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:00:39 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s)
		return ((char *)s);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	last;

	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	i = 1;
	last = 0;
	while (s[i - 1])
	{
		if (s[i - 1] == (unsigned char)c)
			last = i;
		i++;
	}
	if (!last)
		return (0);
	return ((char *)s + last - 1);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (j == size)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (j == size)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}


