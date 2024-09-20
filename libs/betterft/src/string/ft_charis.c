/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:38:04 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:38:50 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_isalnum(int c)
{
	if (!(c >= 'A' && c <= 'Z'))
		if (!(c >= 'a' && c <= 'z'))
			if (!(c >= '0' && c <= '9'))
				return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	if (!(c >= 'A' && c <= 'Z'))
		if (!(c >= 'a' && c <= 'z'))
			return (0);
	return (1);
}

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
