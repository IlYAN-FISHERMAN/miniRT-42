/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:49:04 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:39:19 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	output;
	int	sign;
	int	idx;

	output = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -sign;
	while (ft_strchr(base, *str) && *ft_strchr(base, *str))
	{
		idx = 0;
		while (base[idx] && *str != base[idx])
			idx++;
		output = output * ft_strlen(base) + idx;
		str++;
	}
	return (sign * output);
}

int	ft_atoi(const char *str)
{
	return (ft_atoi_base(str, "0123456789"));
}
