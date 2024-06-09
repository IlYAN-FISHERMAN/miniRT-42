/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:25:15 by rude-jes          #+#    #+#             */
/*   Updated: 2024/05/10 20:38:13 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../betterft.h"

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
