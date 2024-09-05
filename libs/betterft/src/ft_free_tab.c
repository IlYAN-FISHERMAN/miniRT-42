/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:42 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/03 03:06:55 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../betterft.h"

int	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return (1);
	while (*(tab + i))
		i++;
	while (i >= 0)
	{
		gfree(*(tab + i));
		i--;
	}
	gfree(tab);
	return (0);
}
