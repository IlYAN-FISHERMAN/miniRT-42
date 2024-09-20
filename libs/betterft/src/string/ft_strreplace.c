/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:19:49 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:58:56 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	count_replaces(char *src, char *old)
{
	size_t	count;
	char	*tmp;

	count = -1;
	tmp = ft_strstr(src, old);
	while (count++, tmp && *tmp)
		tmp = ft_strstr(tmp + 1, old);
	return (count);
}

static void	fill_str(char *src, char *old, char *new, char *output)
{
	char	*needle;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		needle = ft_strstr(src + i, old);
		if (src + i == needle)
		{
			ft_strncat(output, new, ft_strlen(new));
			i += ft_strlen(old);
			j += ft_strlen(new);
		}
		else
		{
			output[j] = src[i];
			i++;
			j++;
		}
	}
}

char	*ft_strreplace(char *src, char *old, char *new)
{
	char	*output;
	int		count;
	size_t	size;

	if (!ft_strstr(src, old))
		return (ft_strdup(src));
	count = count_replaces(src, old);
	if (!count)
		return (ft_strdup(src));
	size = ((ft_strlen(src) + (ft_strlen(new) - ft_strlen(old)) * count) + 1);
	output = galloc(size);
	if (!output)
		return (0);
	fill_str(src, old, new, output);
	return (output);
}

static void	fill_str_first(char *src, char *old, char *new, char *output)
{
	char	*needle;
	size_t	size;

	size = ft_strlen(src) - ft_strlen(old) + ft_strlen(new) + 1;
	needle = ft_strstr(src, old);
	ft_strlcpy(output, src, needle - src + 1);
	ft_strlcat(output, new, size);
	ft_strlcat(output, needle + ft_strlen(old), size);
}

char	*ft_strreplace_first(char *src, char *old, char *new)
{
	char	*output;
	size_t	size;

	if (!ft_strstr(src, old))
		return (ft_strdup(src));
	size = ((ft_strlen(src) + (ft_strlen(new) - ft_strlen(old))) + 1);
	output = galloc(size);
	if (!output)
		return (0);
	fill_str_first(src, old, new, output);
	return (output);
}
