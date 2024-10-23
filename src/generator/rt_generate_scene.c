/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generate_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:50 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/23 06:39:56 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"

int	gener_amb(int fd)
{
	ft_putstr_fd("A    ", fd);
	ft_putstr_fd(" 0.4  ", fd);
	if (!put_xyz_int(fd, 254, 255))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_lig(int fd, bool	bonus)
{
	ft_putstr_fd("L    ", fd);
	if (!put_xyz_double(fd, -2, 2))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_double(0, 1, fd))
		return (0);
	if (bonus)
	{
		ft_putstr_fd("     ", fd);
		if (!put_xyz_int(fd, 0, 255))
			return (0);
	}
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_win(char *height, char *width, int fd)
{
	ft_putstr_fd("R    ", fd);
	ft_putstr_fd(height, fd);
	ft_putstr_fd("     ", fd);
	ft_putstr_fd("     ", fd);
	ft_putstr_fd(width, fd);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_cam(int fd)
{
	ft_putstr_fd("C 0.00,5.00,-43.00 0.00,-0.10,1.00 65\n", fd);
	/*if (!put_xyz_int(fd, -30, -10))*/
	/*	return (0);*/
	/*ft_putstr_fd("     ", fd);*/
	/*if (!put_xyz_int(fd, -1, 1))*/
	/*	return (0);*/
	/*ft_putstr_fd("     ", fd);*/
	/*if (!ran_int(70, 80, fd))*/
	/*	return (0);*/
	/*ft_putstr_fd("\n", fd);*/
	return (1);
}
