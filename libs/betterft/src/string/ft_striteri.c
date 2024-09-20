/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:44:52 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:40:24 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*sreader;

	sreader = s;
	while (*(sreader++))
		f(sreader - 1 - s, sreader - 1);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*output;
	char			*owriter;

	output = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!output)
		return (0);
	owriter = output;
	while (owriter++, *(s++))
		*(owriter - 1) = f(owriter - 1 - output, *(s - 1));
	return (output);
}
