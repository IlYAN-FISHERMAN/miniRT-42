#include "parsing.h"

int	strchr_light(t_scene *tmp)
{
	while (tmp && tmp->content)
	{
		if (((t_object *)tmp->content)->type == o_light)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_light_range(char **str, t_minirt *minirt, bool *bonus)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Light: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	if (ft_atof(str[2]) < 0.0 || ft_atof(str[2]) > 1.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Light: "
			"Bad range for brightness\n[brightness: >0.0/<1.0]", NULL}, str[2]);
	if (*bonus)
		check_rgb_range((char *[]){"miniRT", "parsing: Light: "
			"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
			str[3], minirt);
}

void	check_light_format_bonus(char **str, t_minirt **minirt, bool *bonus)
{
	if (ft_strlen_tab(str) < 3 || ft_strlen_tab(str) > 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: Light: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [brightness: 0.0] [bonus][rgb: 0.0.0]\n");
	if (!only_digit_xyz(str[1], *minirt) && !only_float_xyz(str[1], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_float(str[2]) && !only_digit(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", "Light: Bad brightness format\n"
			"[brightness: 0.0]", NULL}, str[2]);
	if (str[3] && !only_digit_xyz(str[3], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[3]);
	if (str[3])
		if (only_digit_xyz(str[3], *minirt))
			*bonus = true;
	if (!str[3])
		*bonus = false;
}

void	check_light_format(char **str, t_minirt **minirt, bool *bonus)
{
	if (strchr_light((*minirt)->scene))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one Light accepted");
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: Light: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [brightness: 0.0] [bonus][rgb: 0.0.0]\n");
	if (!only_digit_xyz(str[1], *minirt) && !only_float_xyz(str[1], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_float(str[2]) && !only_digit(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", "Light: Bad brightness format\n"
			"[brightness: 0.0]", NULL}, str[2]);
	if (str[3] && !only_digit_xyz(str[3], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[3]);
	*bonus = false;
}

void	get_light(char **str, t_minirt **minirt)
{
	t_scene	*light;
	t_light	*tmp;
	bool	bonus;

	if (BONUS)
		check_light_format_bonus(str, minirt, &bonus);
	else
		check_light_format(str, minirt, &bonus);
	check_light_range(str, *minirt, &bonus);
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
				(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	ft_lstadd_back(&(*minirt)->scene, light);
}
