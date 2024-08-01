#include "miniRT.h"
#include "camera/camera.h"
#include "camera/image.h"
#include "exit_handler/exit_handler.h"
#include "vectors/vectors.h"

static void	init_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->win.windo, 17, 0, secure_exit, minirt);
}

void	*init_minirt_mlx(t_minirt *minirt)
{
	minirt->win.mlx = mlx_init();
	if (!minirt->win.mlx)
		crash_exit(minirt, NULL, "ntm");
	minirt->win.windo = \
		mlx_new_window(minirt->win.mlx, minirt->size->width,
			minirt->size->height, "miniRT");
	if (!minirt->win.windo)
		crash_exit(minirt, NULL, "windo malloc fail");
	init_hooks(minirt);
	return (minirt);
}

int	only_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	only_float(char *str)
{
	int		i;
	bool	dot;

	i = -1;
	dot = false;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.' && dot)
			return (0);
		if (str[i] == '.')
			dot = true;
	}
	return (1);
}

int	only_digit_xyz(char *split, t_minirt *minirt)
{
	int		i;
	int		j;
	char	**str;

	j = -1;
	str = ft_split(split, ',');
	if (!str)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	while (str[++j])
	{
		i = -1;
		while (str[j][++i])
			if (ft_isdigit(str[j][i]))
				return (0);
	}
	ft_free_tab(str);
	return (1);
}

int	only_float_xyz(char *split, t_minirt *minirt)
{
	int		i;
	int		j;
	bool	dot;
	char	**str;

	j = -1;
	str = ft_split(split, ',');
	if (!str)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	while (str[++j])
	{
		i = -1;
		dot = false;
		while (str[j][++i])
		{
			if ((ft_isdigit(str[j][i]) && str[j][i] != '.')
				|| (str[j][i] == '.' && dot))
				return (0);
			if (str[j][i] == '.')
				dot = true;
		}
	}
	ft_free_tab(str);
	return (1);
}

float	ft_atof(char *str)
{
	float	nb;
	int		i;
	int		j;

	i = 0;
	nb = 0;
	j = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - 48);
		if (str[i] == '.')
		{
			while (str[++i] && ++j)
				nb = (nb * (float)pow(10, j) + (str[i] - 48)) / pow(10, j);
			return (nb);
		}
	}
	return (nb);
}

void	check_size_format(char **str, t_minirt **minirt)
{
	if ((!only_digit(str[1])) || (!only_digit(str[2])))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only digit accepted");
	if ((ft_atoi(str[1]) > 5000 || ft_atoi(str[1]) < 100)
		|| (ft_atoi(str[2]) > 5000 || ft_atoi(str[1]) < 100))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Bad number >100/<7680");
	if (str[4])
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"Too many information with size");
}

void	check_cam_format(char **str, t_minirt **minirt)
{
	if ((!only_digit_xyz(str[1], *minirt) && !only_float_xyz(str[1], *minirt))
		|| (!only_digit_xyz(str[2], *minirt)) || (!only_digit(str[3])))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only digit accepted");
	if (ft_atoi(str[3]) > 180 || ft_atoi(str[3]) < 0)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Bad number >100/<7680");
	if (str[4])
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"Too many information with cam");
}

void	get_size(char **str, t_minirt **minirt)
{
	if ((*minirt)->size)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one R accepted");
	check_size_format(str, minirt);
	(*minirt)->size = new_image(ft_atoi(str[1]), ft_atoi(str[2]));
	if (!(*minirt)->size)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}

void	get_cam_info(t_point3 *origin, t_vector3 *target,
				t_minirt *minirt, char **str)
{
	char	**split;

	split = ft_split(str[1], ',');
	if (!split)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	origin->x = ft_atof(split[0]);
	origin->y = ft_atof(split[1]);
	origin->z = ft_atof(split[2]);
	ft_free_tab(split);
	split = ft_split(str[2], ',');
	if (!split)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	target->x = ft_atof(split[0]);
	target->y = ft_atof(split[1]);
	target->z = ft_atof(split[2]);
	ft_free_tab(split);
}

void	get_cam(char **str, t_minirt **minirt)
{
	t_point3	origin;
	t_vector3	target;

	if ((*minirt)->cam)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one C accepted");
	check_cam_format(str, minirt);
	get_cam_info(&origin, &target, *minirt, str);
	if ((*minirt)->size)
		(*minirt)->cam = new_camera(origin, target, (float)ft_atoi(str[3]),
				(float)((*minirt)->size->width / (*minirt)->size->height));
	else
		(*minirt)->cam = new_camera(origin, target, (float)ft_atoi(str[3]),
				(float)WIDTH / HEIGHT);
	if (!(*minirt)->cam)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}

void	pars_obj(char **str, t_minirt **minirt)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!ft_strcmp(str[j], "R"))
			get_size(str, minirt);
		else if (!ft_strcmp(str[j], "A"))
			get_amb(str, minirt);
		else if (!ft_strcmp(str[j], "C"))
			get_cam(str, minirt);
		else if (!ft_strcmp(str[j], "L"))
			get_lig(str, minirt);
		else if (!ft_strcmp(str[j], "pl") || !ft_strcmp(str[j], "cy")
			|| !ft_strcmp(str[j], "sp"))
			get_obj(str, minirt);
		else
			crash_exit(*minirt,
				(char *[]){"miniRT", "parsing: bad string format: ", NULL},
				str[j]);
	}
}

void	pars_map(char **av, t_minirt **minirt)
{
	int		j;
	char	**str;
	char	*gnl;

	j = -1;
	str = NULL;
	(*minirt)->fd = open(av[1], O_RDONLY);
	if ((*minirt)->fd == -1
		&& ft_printf("miniRT: %s: No such file or directory", av[1]))
		secure_exit(*minirt);
	while (av[++j])
	{
		gnl = ft_get_next_line((*minirt)->fd);
		if (!gnl)
			break ;
		str = ft_split(gnl, 32);
		if (!str)
			crash_exit(*minirt,
				(char *[]){"miniRT", "parsing", NULL}, "Malloc fail");
		gfree(gnl);
		pars_obj(str, minirt);
		ft_free_tab(str);
	}
}

void	check_error(int ac, char **av)
{
	if (ac <= 1 && printf("miniRT: Need <*.rt> file\n"))
		secure_exit(NULL);
	if ((!ft_strchr(av[1], '.') \
		|| ft_strncmp(ft_strchr(av[1], '.'), ".rt", 4))
		&& ft_printf("miniRT: bad format file, only .rt file accepted\n"))
		exit(EXIT_FAILURE);
}

t_minirt	*init_minirt(t_minirt *minirt, int argc, char **argv)
{
	check_error(argc, argv);
	pars_map(argv, &minirt);
	return (minirt);
}
