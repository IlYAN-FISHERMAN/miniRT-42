/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:38:27 by ilyanar           #+#    #+#             */
/*   Updated: 2024/09/05 01:17:18 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"

int	put_xyz_int(int fd, int min, int max)
{
	if (!ran_int(min, max, fd))
		return (0);
	ft_putstr_fd(",", fd);
	if (!ran_int(min, max, fd))
		return (0);
	ft_putstr_fd(",", fd);
	if (!ran_int(min, max, fd))
		return (0);
	return (1);
}

int	put_xyz_float(int fd, int min, int max)
{
	if (!ran_float(min, max, fd))
		return (0);
	ft_putstr_fd(",", fd);
	if (!ran_float(min, max, fd))
		return (0);
	ft_putstr_fd(",", fd);
	if (!ran_float(min, max, fd))
		return (0);
	return (1);
}

int	exit_generator(int fd, const char *name)
{
	close(fd);
	unlink(name);
	return (-1);
}

int	rt_generator(char *height, char *width, bool bonus)
{
	const char	name[] = "maps/standard/generate_map.rt";
	int			fd;

	srand((unsigned int)time(NULL));
	fd = 0;
	unlink(name);
	fd = open(name, O_CREAT | O_RDWR, 0777);
	if (fd == -1 || !gener_win(height, width, fd) || !gener_amb(fd)
		|| !gener_cam(fd) || !gener_lig(fd, bonus) || !gener_obj(fd))
		return (exit_generator(fd, name));
	close(fd);
	return (fd);
}
