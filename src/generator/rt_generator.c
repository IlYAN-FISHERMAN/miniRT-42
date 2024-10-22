/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_generator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:47:54 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/22 01:09:48 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_generate.h"
#include <sys/fcntl.h>
#include <unistd.h>

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

int	put_xyz_double(int fd, int min, int max)
{
	if (!ran_double(min, max, fd))
		return (0);
	ft_putstr_fd(",", fd);
	if (!ran_double(min, max, fd))
		return (0);
	ft_putstr_fd(",", fd);
	if (!ran_double(min, max, fd))
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
	const char	name[] = "generate_map.rt";
	int			fd;

	unlink("generate_map.rt");
	srand((unsigned int)time(NULL));
	fd = open(name, O_CREAT | O_RDWR, 0777);
	if (fd == -1 || !gener_win(height, width, fd) || !gener_amb(fd)
		|| !gener_cam(fd) || !gener_lig(fd, bonus) || !gener_obj(fd))
		return (exit_generator(fd, name));
	close(fd);
	fd = open("generate_map.rt", O_RDONLY, 0777);
	return (fd);
}
