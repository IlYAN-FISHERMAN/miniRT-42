/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generator_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:10:49 by ilyanar           #+#    #+#             */
/*   Updated: 2024/07/22 15:11:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"

int	gener_sp(int fd)
{
	ft_putstr_fd("sp    ", fd);
	if (!put_xyz_float(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_float(0, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 256))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_cy(int fd)
{
	ft_putstr_fd("cy    ", fd);
	if (!put_xyz_float(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_float(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_float(0, 30, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_float(0, 30, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 256))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_pl(int fd)
{
	ft_putstr_fd("pl    ", fd);
	if (!put_xyz_float(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_float(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 256))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_obj(int fd)
{
	int	obj_nb;
	int	enu;

	enu = 0;
	obj_nb = gener_int(1, 10);
	ft_putstr_fd("\n", fd);
	while (obj_nb > 0)
	{
		enu = gener_int(1, 3);
		if (enu == 1)
			if (!gener_pl(fd))
				return (0);
		if (enu == 2)
			if (!gener_sp(fd))
				return (0);
		if (enu == 3)
			if (!gener_cy(fd))
				return (0);
		obj_nb--;
	}
	return (1);
}
