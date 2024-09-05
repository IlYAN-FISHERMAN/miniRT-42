#include "parsing.h"

void	check_sp_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "sp bad number of arg");
	if (!only_float_xyz(str[1], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: sp bad number format", NULL}, str[1]);
	if (!only_float(str[2]) && !only_digit(str[2]))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: sp bad number format", NULL}, str[2]);
	if (!only_digit_xyz(str[3], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: sp bad number format", NULL}, str[3]);
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
	if (!ft_atoi_rgb(&tmp->color.r, &tmp->color.g, &tmp->color.b,
			ft_split(str[3], ',')))
		crash_exit(*minirt,
			(char *[]){"miniRT",
			"parsing: sp bad rgb format", NULL}, str[3]);
	ft_lstadd_back(&(*minirt)->scene, scene);
}
