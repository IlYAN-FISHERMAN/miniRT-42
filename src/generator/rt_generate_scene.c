/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generate_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:50 by ilyanar           #+#    #+#             */
/*   Updated: 2024/07/22 15:19:11 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"

int	gener_amb(int fd)
{
	ft_putstr_fd("A    ", fd);
	if (!ran_float(0, 1, fd))
		return (0);
	ft_putstr_fd("    ", fd);
	if (!put_xyz_int(fd, 0, 256))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}

int	gener_lig(int fd, bool	bonus)
{
	ft_putstr_fd("L    ", fd);
	if (!put_xyz_float(fd, -10, 10))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_float(0, 1, fd))
		return (0);
	if (bonus)
	{
		ft_putstr_fd("     ", fd);
		if (!put_xyz_int(fd, 0, 256))
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
	ft_putstr_fd("C    ", fd);
	if (!put_xyz_int(fd, 90, 180))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!put_xyz_int(fd, -1, 1))
		return (0);
	ft_putstr_fd("     ", fd);
	if (!ran_int(60, 180, fd))
		return (0);
	ft_putstr_fd("\n", fd);
	return (1);
}
