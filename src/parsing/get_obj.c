#include "parsing.h"

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

void	get_obj(char **str, t_minirt **minirt)
{
	if (!ft_strcmp(str[0], "pl"))
		get_pl(str, minirt);
	else if (!ft_strcmp(str[0], "cy"))
		get_cy(str, minirt);
	else if (!ft_strcmp(str[0], "sp"))
		get_sp(str, minirt);
}

void	pars_obj(char **str, t_minirt **minirt)
{
	if (str)
	{
		if (!ft_strcmp(str[0], "R") || !ft_strcmp(str[0], "r"))
			get_size(str, minirt);
		else if (!ft_strcmp(str[0], "A") || !ft_strcmp(str[0], "a"))
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
				(char *[]){"miniRT", "parsing: bad string format\n"
				"unknown object:", NULL},
				str[0]);
	}
}
