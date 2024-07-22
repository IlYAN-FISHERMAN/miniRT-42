#include "miniRT.h"
#include "exit_handler/exit_handler.h"

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
		mlx_new_window(minirt->win.mlx, HEIGHT, WIDTH, "miniRT");
	if (!minirt->win.windo)
		crash_exit(minirt, NULL, "rui je t\'aime");
	init_hooks(minirt);
	return (minirt);
}

t_size	*get_size(char **str, t_minirt **minirt)
{
	int		j;
	t_size	*size;

	j = 1;
	(void)j;
	(void)size;
	(void)str;
	(void)minirt;
	return (NULL);
}

void	pars_obj(char **str, t_minirt **minirt)
{
	int	j;

	j = 0;
	if (!str || !*str)
		return ;
	while (str[j])
	{
		if (!ft_strcmp(str[j], "R"))
			get_size(str, minirt);
		else if (!ft_strcmp(str[j], "A"))
			;
		else if (!ft_strcmp(str[j], "C"))
			;
		else if (!ft_strcmp(str[j], "L"))
			;
		else if (!ft_strcmp(str[j], "pl"))
			;
		else if (!ft_strcmp(str[j], "cy"))
			;
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
