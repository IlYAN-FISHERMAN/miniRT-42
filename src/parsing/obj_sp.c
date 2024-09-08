#include "parsing.h"

void	check_sp_range(char **str, t_minirt *minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Sp: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	if (ft_atof(str[2]) < -10000.0 || ft_atof(str[2]) > 10000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Sp: "
			"Bad range for diameter\n[diameter: >-10k.0/<10k.0]", NULL},
			str[2]);
	check_rgb_range((char *[]){"miniRT", "parsing: Sp: "
		"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
		str[3], minirt);
}

void	check_sp_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing: Sp: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [diameter: 0.0] [rgb: 0.0.0]\n");
	if (!only_float_xyz(str[1], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Sp: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_float(str[2]) && !only_digit(str[2]))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", "Sp: Bad diameter format\n"
			"[diameter: 0.0]", NULL}, str[2]);
	if (!only_digit_xyz(str[3], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Sp: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[3]);
}

void	get_sp(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	t_sphere	*tmp;

	check_sp_info(str, *minirt);
	check_sp_range(str, *minirt);
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
