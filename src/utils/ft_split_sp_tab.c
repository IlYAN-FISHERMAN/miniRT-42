/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sp_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:42:45 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:42:47 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	*ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	ft_count_words(char const *s)
{
	size_t	nb;
	size_t	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == 32 || s[i] == '\t')
			i++;
		if (s[i] != 32 && s[i] != '\t')
		{
			while ((s[i] != 32 && s[i] != '\t')
				&& s[i])
				i++;
			nb++;
		}
	}
	return (nb);
}

static size_t	ft_lenc(const char *s)
{
	size_t	i;

	i = 0;
	while ((s[i] != 32 && s[i] != '\t')
		&& s[i])
		i++;
	return (i + 1);
}

char	**ft_split_sp_tab(char const *s)
{
	size_t	j;
	char	**tab;

	j = 0;
	tab = ft_calloc(ft_count_words(s) + 1, sizeof(char **));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == 32 || *s == '\t')
			s++;
		if (*s && !(*s == 32 || *s == '\t'))
		{
			tab[j] = ft_calloc(ft_lenc(s), sizeof(char));
			if (!tab[j])
				return (ft_free(tab));
			ft_memcpy(tab[j], s, ft_lenc(s) - 1);
			j++;
			while (*s != 32 && *s != '\t' && *s)
				s++;
		}
	}
	return (tab);
}
