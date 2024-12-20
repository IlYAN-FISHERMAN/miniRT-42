/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generate_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:44:05 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:44:06 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"

int	ran_int(int min, int max, int fd)
{
	char	*str;

	str = ft_itoa(min + rand() % (max - min + 1));
	if (!str)
		return (0);
	ft_putstr_fd(str, fd);
	free(str);
	return (1);
}

int	gener_int(int min, int max)
{
	return (min + rand() % (max - min + 1));
}

int	ran_double(int min, int max, int fd)
{
	char	*str;
	int		nb;

	nb = min + rand() % (max - min + 1);
	str = ft_itoa(min + rand() % (max - min + 1));
	if (!str)
		return (0);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(".", fd);
	if (nb < max && ((nb > min && nb > 0) || (nb > min && nb < 0)))
	{
		if (!ran_int(0, 10, fd))
			return (-1);
	}
	else
		ft_putstr_fd("0", fd);
	free(str);
	return (1);
}
