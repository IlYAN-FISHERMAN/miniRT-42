/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strr_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:30:35 by ilyanar           #+#    #+#             */
/*   Updated: 2024/06/09 19:14:23 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../betterft.h"

char	**strr_realloc(char **str, char *neww)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str)
		while (str[i] != NULL)
			i++;
	tab = ft_calloc(i + 2, sizeof(char *));
	if (!tab)
		return (NULL);
	while (i > 0 && j < i)
	{
		tab[j] = str[j];
		j++;
	}
	tab[j] = ft_strdup(neww);
	if (!tab[j])
		return (NULL);
	gfree(str);
	return (tab);
}
