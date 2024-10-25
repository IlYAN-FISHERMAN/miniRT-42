#include "rt_generate.h"

int	gener_amb(int fd)
{
	ft_putstr_fd("A    ", fd);
	ft_putstr_fd(" 0.4  ", fd);
	if (!put_xyz_int(fd, 255, 255))
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
	if (!ran_double(1, 1, fd))
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
	ft_putstr_fd("C 0,0,-30 0,0,1 80\n", fd);
	return (1);
}
