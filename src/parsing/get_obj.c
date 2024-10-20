#include "ft_string.h"
#include "parsing.h"

t_scene	*get_scene_struct(t_minirt **minirt)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
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
	else if (!ft_strcmp(str[0], "co"))
		get_co(str, minirt);
}

int	is_obj(char *str)
{
	if (!ft_strcmp(str, "pl") || !ft_strcmp(str, "cy") || !ft_strcmp(str, "sp")
		|| !ft_strcmp(str, "co") || !ft_strcmp(str, "cu")
		|| !ft_strcmp(str, "py"))
		return (1);
	return (0);
}

int	is_mat(char *str)
{
	if (!ft_strcmp(str, "metal") || !ft_strcmp(str, "plastic")
		|| !ft_strcmp(str, "glass") || !ft_strcmp(str, "mirror"))
		return (1);
	return (0);
}

void	pars_obj(char **str, t_minirt **minirt)
{
	if (!ft_strcmp(str[0], "R") || !ft_strcmp(str[0], "r"))
		get_size(str, minirt);
	else if (!ft_strcmp(str[0], "A") || !ft_strcmp(str[0], "a"))
		get_amb(str, minirt);
	else if (!ft_strcmp(str[0], "C") || !ft_strcmp(str[0], "c"))
		get_cam(str, minirt);
	else if (!ft_strcmp(str[0], "L") || !ft_strcmp(str[0], "l"))
		get_light(str, minirt);
	else if (is_obj(str[0]))
		get_obj(str, minirt);
	else if (!ft_strcmp("define", str[0]))
			/*get_material(str, minirt);*/
		;
	else if (str[0][0] == '#')
		;
	else
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: bad string format\n"
			"unknown object", NULL},
			str[0]);
}
