#include "parsing.h"

void	check_light_format(char **str, t_minirt **minirt, bool *bonus)
{
	if (ft_strlen_tab(str) < 3 || ft_strlen_tab(str) > 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L bad number of arg [3/4]");
	if (!only_digit_xyz(str[1], *minirt) && !only_float_xyz(str[1], *minirt))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing:\nL only\
0,0,0 xyz_float [><255]", NULL}, str[1]);
	if (!only_float(str[2]) && !only_digit(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: L only one\
float number", NULL}, str[2]);
	if (str[3] && !only_digit_xyz(str[3], *minirt))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing:\nL only\
0,0,0 rgb_digit [>0<255]", NULL}, str[3]);
	if (str[3])
		if (only_digit_xyz(str[3], *minirt))
			*bonus = true;
	if (!str[3])
		*bonus = false;
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
		if (!ft_atoi_rgb(&tmp->rgb.r, &tmp->rgb.g, &tmp->rgb.b,
				ft_split(str[3], ',')))
			crash_exit(*minirt,
				(char *[]){"miniRT", "parsing: L rgb bad format",
				NULL}, str[3]);
	ft_lstadd_back(&(*minirt)->scene, light);
}
