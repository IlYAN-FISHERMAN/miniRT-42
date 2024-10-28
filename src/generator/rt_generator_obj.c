/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generator_obj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:44:12 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:44:13 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "rt_generate.h"

int	gener_sp(int fd)
{
	ft_putstr_fd("sp    ", fd);
	if (!put_xyz_double(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(1, 10, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	return (1);
}

int	gener_cy(int fd)
{
	ft_putstr_fd("cy    ", fd);
	if (!put_xyz_double(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_double(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(1, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(1, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	return (1);
}

int	gener_co(int fd)
{
	ft_putstr_fd("co    ", fd);
	if (!put_xyz_double(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_double(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(1, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(1, 20, fd))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, 0, 255))
		return (0);
	return (1);
}

static void	gener_mat(int fd)
{
	int	gen;

	gen = gener_int(0, 9);
	if (gen == 0 || gen == 9)
		ft_putstr_fd("\n", fd);
	if (gen == 1)
		ft_putstr_fd(" metal\n", fd);
	if (gen == 2)
		ft_putstr_fd(" plastic\n", fd);
	if (gen == 3)
		ft_putstr_fd(" mirror\n", fd);
	if (gen == 4)
		ft_putstr_fd(" glass\n", fd);
	if (gen == 5)
		ft_putstr_fd(" wood\n", fd);
	if (gen == 6)
		ft_putstr_fd(" mat\n", fd);
	if (gen == 7)
		ft_putstr_fd(" bricks\n", fd);
	if (gen == 8)
		ft_putstr_fd(" checkerboard\n", fd);
}

int	gener_obj(int fd)
{
	int	obj_nb;
	int	enu;

	enu = 0;
	obj_nb = gener_int(3, 10);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("pl 0,-15,0 0,1,0 255,255,255\n", fd);
	while (obj_nb > 0)
	{
		enu = gener_int(1, 3);
		if (enu == 1)
			if (!gener_sp(fd))
				return (0);
		if (enu == 2)
			if (!gener_cy(fd))
				return (0);
		if (enu == 3)
			if (!gener_co(fd))
				return (0);
		gener_mat(fd);
		obj_nb--;
	}
	return (1);
}
