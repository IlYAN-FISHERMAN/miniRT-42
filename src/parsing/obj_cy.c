#include "../miniRT.h"
#include "../objects/cylinder.h"
#include "../exit_handler/exit_handler.h"

void	check_cy_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 6)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "cy bad number of arg");
	if (!only_float_xyz(str[1], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: cy bad number format", NULL}, str[1]);
	if (!only_float_xyz(str[2], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: cy bad number format", NULL}, str[2]);
	if (!only_float(str[3]) && !only_digit(str[3]))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: cy bad number format", NULL}, str[3]);
	if (!only_float(str[4]) && !only_digit(str[4]))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: cy bad number format", NULL}, str[4]);
	if (!only_digit_xyz(str[5], minirt))
		crash_exit(minirt,
			(char *[]){"miniRT",
			"parsing: cy bad number format", NULL}, str[5]);
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
	ft_lstadd_back(&(*minirt)->scene, scene);
}
