/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:25:15 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:44:52 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	**ft_tabadd(char **tab, char *str)
{
	size_t	len;

	if (!tab)
	{
		tab = galloc(2 * sizeof(char *));
		if (!tab)
			return (0);
		tab[0] = str;
		tab[1] = 0;
		return (tab);
	}
	len = ft_tablen(tab);
	tab = ft_reallocf(tab, len * sizeof(char *), (len + 2) * sizeof(char *));
	if (!tab)
		return (0);
	tab[len] = str;
	tab[len + 1] = 0;
	return (tab);
}

char	*ft_tabjoin(char **array)
{
	char	*output;
	char	*tmp;

	if (!array || !*array)
		return (0);
	output = ft_strdup(*array);
	if (!output)
		return (0);
	array++;
	while (*array)
	{
		tmp = output;
		output = ft_strjoin(output, *array);
		gfree(tmp);
		if (!output)
			return (0);
		array++;
	}
	return (output);
}

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
