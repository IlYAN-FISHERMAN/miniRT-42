#include "miniRT.h"
#include "camera/camera.h"
#include "camera/image.h"
#include "exit_handler/exit_handler.h"
#include "objects/cylinder.h"
#include "objects/objects.h"
#include "objects/plane.h"
#include "objects/sphere.h"
#include "rays/intersect.h"
#include "vectors/vectors.h"

static void	init_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->win.windo, 17, 0, secure_exit, minirt);
}

int	ft_strlen_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str && str[++i])
		;
	return (i);
}

void	*init_minirt_mlx(t_minirt *minirt)
{
	minirt->win.mlx = mlx_init();
	if (!minirt->win.mlx)
		crash_exit(minirt, NULL, "mlx failed");
	minirt->win.windo = \
		mlx_new_window(minirt->win.mlx, minirt->size->width,
			minirt->size->height, "miniRT");
	if (!minirt->win.windo)
		crash_exit(minirt, NULL, "windo malloc fail");
	init_hooks(minirt);
	return (minirt);
}

float	ft_atof(char *str)
{
	float	nb;
	int		i;
	int		j;
	int		sign;

	i = -1;
	nb = 0;
	j = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[++i])
	{
		if (str[i] == '.')
		{
			while (str[++i] && ++j)
				nb = (nb * (float)pow(10, j) + (str[i] - 48)) / pow(10, j);
			return (nb * sign);
		}
		nb = nb * 10 + (str[i] - 48);
	}
	return (nb * sign);
}

int	ft_atof_xyz(float *x, float *y, float *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atof(str[0]);
	*y = ft_atof(str[1]);
	*z = ft_atof(str[2]);
	ft_free_tab(str);
	return (1);
}

int	ft_atoi_xyz(int *x, int *y, int *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atoi(str[0]);
	*y = ft_atoi(str[1]);
	*z = ft_atoi(str[2]);
	ft_free_tab(str);
	return (1);
}

int	only_digit(char *str)
{
	int		nb;
	char	*tmp;

	nb = ft_atoi(str);
	tmp = ft_itoa(nb);
	if (!tmp)
		return (0);
	if (ft_strcmp(str, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	only_float(char *str)
{
	int		i;

	i = -1;
	if (!str || str[0] == '.' || !ft_strchr(str, '.'))
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i] && str[i] != '.')
		if (!ft_isdigit(str[i]) || !str[i + 1])
			return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	only_digit_xyz(char *split, t_minirt *minirt)
{
	int		j;
	char	**str;

	if (!ft_strchr(split, ','))
		return (0);
	j = -1;
	str = ft_split(split, ',');
	if (!str)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	while (str[++j])
	{
		if (!only_digit(str[j]) || j >= 3)
		{
			ft_free_tab(str);
			return (0);
		}
	}
	ft_free_tab(str);
	if (j <= 2)
		return (0);
	return (1);
}

int	only_float_xyz(char *split, t_minirt *minirt)
{
	int		j;
	char	**str;

	j = -1;
	if (!ft_strchr(split, ','))
		return (0);
	str = ft_split(split, ',');
	if (!str)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	while (str[++j])
	{
		if (!only_float(str[j]))
		{
			ft_free_tab(str);
			return (0);
		}
	}
	if (j <= 2 || j > 3)
		return (0);
	ft_free_tab(str);
	return (1);
}

void	check_size_format(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L bad format");
	if ((!only_digit(str[1])) || (!only_digit(str[2])))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Size: only digit accepted");
	if ((ft_atoi(str[1]) > 7680 || ft_atoi(str[1]) < 100)
		|| (ft_atoi(str[2]) > 7680 || ft_atoi(str[1]) < 100))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Size: range >100/<7680");
	if (str[4])
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"Too many information with size");
}

void	check_cam_format(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L bad format");
	if (!only_float_xyz(str[1], *minirt))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: only float accepted", NULL}, str[1]);
	if (!only_float_xyz(str[2], *minirt))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: only float accepted", NULL}, str[2]);
	if (!only_digit(str[3]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: only digit accepted", NULL}, str[3]);
	if (ft_atoi(str[3]) > 180 || ft_atoi(str[3]) < 0)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"Cam: bad number >0/<180");
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
	if (!ft_atof_xyz(&origin->x, &origin->y, &origin->z, ft_split(str[1], ',')))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "ft_atof_xyz failed");
	if (!ft_atof_xyz(&target->x, &target->y, &target->z, ft_split(str[2], ',')))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "ft_atof_xyz failed");
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

void	check_amb_format(t_minirt **minirt, char **str)
{
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L bad format");
	if (!only_float(str[1]))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing", NULL},
			"Amb, only ambient ratio in float");
	if (!only_digit_xyz(str[2], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing", NULL},
			"Amb, rgb bad format");
	if (str[3])
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"Too many information with amb");
}

void	get_amb(char **str, t_minirt **minirt)
{
	char	**split;

	if ((*minirt)->amb)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one A accepted");
	check_amb_format(minirt, str);
	split = ft_split(str[2], ',');
	if (!split)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	(*minirt)->amb = ft_calloc(1, sizeof(t_amb));
	if (!(*minirt)->amb)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	(*minirt)->amb->light = ft_atof(str[1]);
	(*minirt)->amb->rgb.r = ft_atoi(split[0]);
	(*minirt)->amb->rgb.g = ft_atoi(split[1]);
	(*minirt)->amb->rgb.b = ft_atoi(split[2]);
	ft_free_tab(split);
}

void	check_light_format(char **str, t_minirt **minirt, bool *bonus)
{
	if (ft_strlen_tab(str) < 3 || ft_strlen_tab(str) > 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L bad format");
	if (!only_digit_xyz(str[1], *minirt) || !only_float(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L digit format");
	if (str[3])
		if (only_digit_xyz(str[3], *minirt))
			*bonus = true;
	if (!str[3])
		*bonus = false;
}

t_scene	*get_scene_struct(t_minirt **minirt)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	scene->content = ft_calloc(1, sizeof(t_object));
	if (!scene->content)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	return (scene);
}

void	get_light(char **str, t_minirt **minirt)
{
	t_scene	*light;
	t_light	*tmp;
	bool	bonus;

	check_light_format(str, minirt, &bonus);
	light = get_scene_struct(minirt);
	((t_object *)light->content)->data = ft_calloc(1, sizeof(t_light));
	if (!((t_object *)light->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	((t_object *)light->content)->type = o_light;
	tmp = ((t_object *)light->content)->data;
	ft_atof_xyz(&tmp->pos.x, &tmp->pos.y, &tmp->pos.z, ft_split(str[1], ','));
	tmp->bright = ft_atof(str[2]);
	if (bonus)
		ft_atoi_xyz(&tmp->rgb.r, &tmp->rgb.g, &tmp->rgb.b,
			ft_split(str[3], ','));
	ft_lstadd_back(&(*minirt)->scene, light);
}

void	check_pl_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "pl bad number of arg");
	if (!only_float_xyz(str[1], minirt) || !only_float(str[2])
		|| !only_digit_xyz(str[3], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "pl bad number format");
}

void	check_cy_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 6)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "cy bad number of arg");
	if (!only_float_xyz(str[1], minirt) || !only_float_xyz(str[2], minirt)
		|| only_float(str[3]) || only_float(str[4])
		|| only_digit_xyz(str[5], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "sp bad number format");
}

void	check_sp_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "sp bad number of arg");
	if (!only_float_xyz(str[1], minirt) || !only_float(str[2])
		|| !only_digit_xyz(str[3], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "sp bad number format");
}

void	get_pl(char **str, t_minirt **minirt)
{
	t_scene	*scene;
	t_plane	*tmp;

	check_pl_info(str, *minirt);
	scene = get_scene_struct(minirt);
	((t_object *)scene->content)->data = ft_calloc(1, sizeof(t_plane));
	if (!((t_object *)scene->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	((t_object *)scene->content)->type = o_plane;
	tmp = ((t_object *)scene->content)->data;
	ft_atof_xyz(&tmp->origin.x, &tmp->origin.y, &tmp->origin.z,
		ft_split(str[1], ','));
	ft_atof_xyz(&tmp->normal.x, &tmp->normal.y, &tmp->normal.z,
		ft_split(str[2], ','));
	ft_atoi_xyz(&tmp->color.r, &tmp->color.g, &tmp->color.b,
		ft_split(str[3], ','));
}

void	get_cy(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	t_cylin		*tmp;

	check_cy_info(str, *minirt);
	scene = get_scene_struct(minirt);
	((t_object *)scene->content)->data = ft_calloc(1, sizeof(t_cylin));
	if (!((t_object *)scene->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	((t_object *)scene->content)->type = o_cylin;
	tmp = ((t_object *)scene->content)->data;
	ft_atof_xyz(&tmp->origin.x, &tmp->origin.y, &tmp->origin.z,
		ft_split(str[1], ','));
	ft_atof_xyz(&tmp->normal.x, &tmp->normal.y, &tmp->normal.z,
		ft_split(str[2], ','));
	tmp->diam = ft_atof(str[3]);
	tmp->height = ft_atof(str[4]);
	ft_atoi_xyz(&tmp->rgb.r, &tmp->rgb.g, &tmp->rgb.b,
		ft_split(str[5], ','));
}

void	get_sp(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	t_sphere	*tmp;

	check_sp_info(str, *minirt);
	scene = get_scene_struct(minirt);
	((t_object *)scene->content)->data = ft_calloc(1, sizeof(t_sphere));
	if (!((t_object *)scene->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	((t_object *)scene->content)->type = o_sphere;
	tmp = ((t_object *)scene->content)->data;
	ft_atof_xyz(&tmp->origin.x, &tmp->origin.y, &tmp->origin.z,
		ft_split(str[1], ','));
	tmp->radius = ft_atof(str[2]);
	ft_atoi_xyz(&tmp->color.r, &tmp->color.g, &tmp->color.b,
		ft_split(str[3], ','));
}

void	get_obj(char **str, t_minirt **minirt)
{
	if (ft_strcmp(str[0], "pl"))
		get_pl(str, minirt);
	else if (ft_strcmp(str[0], "cy"))
		get_cy(str, minirt);
	else if (ft_strcmp(str[0], "sp"))
		get_sp(str, minirt);
}

void	pars_obj(char **str, t_minirt **minirt)
{
	int	j;

	j = -1;
	if (str)
	{
		if (!ft_strcmp(str[0], "R"))
			get_size(str, minirt);
		else if (!ft_strcmp(str[0], "A"))
			get_amb(str, minirt);
		else if (!ft_strcmp(str[0], "C"))
			get_cam(str, minirt);
		else if (!ft_strcmp(str[0], "L") || !ft_strcmp(str[0], "l"))
			get_light(str, minirt);
		else if (!ft_strcmp(str[0], "pl") || !ft_strcmp(str[0], "cy")
			|| !ft_strcmp(str[0], "sp"))
			get_obj(str, minirt);
		else
			crash_exit(*minirt,
				(char *[]){"miniRT", "parsing: bad string format", NULL},
				str[j]);
	}
}

int	correct_dl(char *gnl)
{
	if (ft_strchr(gnl, '\n'))
		gnl[ft_strlen(gnl) - 1] = '\0';
	return (1);
}

void	get_size_default(t_minirt **minirt)
{
	(*minirt)->size = new_image(WIDTH, HEIGHT);
	if (!(*minirt)->size)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}

void	pars_map(char **av, t_minirt **minirt, int j)
{
	char	**str;
	char	*gnl;

	(*minirt)->fd = open(av[1], O_RDONLY);
	if ((*minirt)->fd == -1 && ft_printf("miniRT: %s: No such file or directory", av[1]))
		secure_exit(*minirt);
	while (av[++j])
	{
		gnl = ft_get_next_line((*minirt)->fd);
		if (!gnl)
			break ;
		if (correct_dl(gnl) && gnl[0] != '\0')
		{
			str = ft_split(gnl, 32);
			if (!str)
				crash_exit(*minirt,
					(char *[]){"miniRT", "parsing", NULL}, "Malloc fail");
			pars_obj(str, minirt);
			ft_free_tab(str);
		}
		gfree(gnl);
	}
	if (!(*minirt)->scene)
		get_size_default(minirt);
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
	pars_map(argv, &minirt, -1);
	return (minirt);
}
