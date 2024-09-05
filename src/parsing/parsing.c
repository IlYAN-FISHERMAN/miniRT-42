#include "parsing.h"

void	pars_obj(char **str, t_minirt **minirt)
{
	if (str)
	{
		if (!ft_strcmp(str[0], "R"))
			get_size(str, minirt);
		else if (!ft_strcmp(str[0], "A"))
			get_amb(str, minirt);
		else if (!ft_strcmp(str[0], "C") || !ft_strcmp(str[0], "c"))
			get_cam(str, minirt);
		else if (!ft_strcmp(str[0], "L") || !ft_strcmp(str[0], "l"))
			get_light(str, minirt);
		else if (!ft_strcmp(str[0], "pl") || !ft_strcmp(str[0], "cy")
			|| !ft_strcmp(str[0], "sp"))
			get_obj(str, minirt);
		else
			crash_exit(*minirt,
				(char *[]){"miniRT", "parsing: bad string format", NULL},
				str[0]);
	}
}

void	pars_map(char **av, t_minirt **minirt)
{
	char	**str;
	char	*gnl;

	(*minirt)->fd = open(av[1], O_RDONLY);
	if ((*minirt)->fd == -1
		&& printf("miniRT: %s: No such file or directory", av[1]))
		secure_exit(*minirt);
	while (true)
	{
		gnl = ft_get_next_line((*minirt)->fd);
		if (!gnl)
			break ;
		if (gnl[0] != '\n' && correct_dl(gnl))
		{
			str = ft_split_sp_tab(gnl);
			if (!str)
				crash_exit(*minirt,
					(char *[]){"miniRT", "parsing", NULL}, "Malloc fail");
			pars_obj(str, minirt);
			ft_free_tab(str);
		}
		gfree(gnl);
	}
	if (!(*minirt)->size)
		get_size_default(minirt);
}
