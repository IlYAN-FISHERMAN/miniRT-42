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

void	check_light_range(char **str, t_minirt *minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Light: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	if (ft_atof(str[2]) < 0.0 || ft_atof(str[2]) > 1.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Light: "
			"Bad range for brightness\n[brightness: >0.0/<1.0]", NULL}, str[2]);
	if (BONUS && str[3])
		check_rgb_range((char *[]){"miniRT", "parsing: Light: "
			"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
			str[3], minirt);
}

void	check_light_format_bonus(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) < 3 || ft_strlen_tab(str) > 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: Light: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [brightness: 0.0] [bonus][rgb: 0.0.0]\n");
	if (!only_digit_xyz(str[1], *minirt) && !only_double_xyz(str[1], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double(str[2]) && !only_digit(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", "Light: Bad brightness format\n"
			"[brightness: 0.0]", NULL}, str[2]);
	if (str[3] && !only_digit_xyz(str[3], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[3]);
}

void	check_light_format(char **str, t_minirt **minirt)
{
	if (strchr_light((*minirt)->world.scene))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one Light accepted");
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: Light: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [brightness: 0.0] [bonus][rgb: 0.0.0]\n");
	if (!only_digit_xyz(str[1], *minirt) && !only_double_xyz(str[1], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Light: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double(str[2]) && !only_digit(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", "Light: Bad brightness format\n"
			"[brightness: 0.0]", NULL}, str[2]);
}

void	get_light(char **str, t_minirt **minirt)
{
	t_scene		*light;
	t_point3	pos;
	t_color		rgb;

	if (BONUS)
		check_light_format_bonus(str, minirt);
	else
		check_light_format(str, minirt);
	check_light_range(str, *minirt);
	light = get_scene_struct(minirt);
	ft_atof_xyz(&pos.x, &pos.y, &pos.z, ft_split(str[1], ','));
	if (BONUS && str[3])
	{
		if (!ft_atoi_rgb(&rgb.r, &rgb.g, &rgb.b, ft_split(str[3], ',')))
			crash_exit(*minirt,
				(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	}
	else
		rgb = (t_color){.r = 255, .g = 255, .b = 255};
	light->content = new_light(pos, rgb, ft_atof(str[2]));
	if (!((t_object *)light->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	ft_lstadd_back(&(*minirt)->world.scene, light);
}
