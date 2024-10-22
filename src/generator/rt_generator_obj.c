/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generator_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:47:39 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/22 01:28:59 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"

int	gener_sp(int fd)
{
	ft_putstr_fd("sp    ", fd);
	if (!put_xyz_double(fd, -2, 2))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(0, 10, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_cy(int fd)
{
	ft_putstr_fd("cy    ", fd);
	if (!put_xyz_double(fd, -2, 2))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_double(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(0, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(0, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_co(int fd)
{
	ft_putstr_fd("co    ", fd);
	if (!put_xyz_double(fd, -2, 2))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_double(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(0, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(0, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_pl(int fd)
{
	ft_putstr_fd("pl    ", fd);
	if (!put_xyz_double(fd, -2, 2))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_double(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_obj(int fd)
{
	int	obj_nb;
	int	enu;

	enu = 0;
	obj_nb = gener_int(3, 10);
	ft_putstr_fd("\n", fd);
	while (obj_nb > 0)
	{
		enu = gener_int(1, 4);
		if (enu == 1)
			if (!gener_pl(fd))
				return (0);
		if (enu == 2)
			if (!gener_sp(fd))
				return (0);
		if (enu == 3)
			if (!gener_cy(fd))
				return (0);
		if (enu == 4)
			if (!gener_co(fd))
				return (0);
		obj_nb--;
	}
	return (1);
}
