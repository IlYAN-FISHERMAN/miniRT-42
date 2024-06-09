/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:10:07 by rude-jes          #+#    #+#             */
/*   Updated: 2024/05/10 20:42:41 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../betterft.h"

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
