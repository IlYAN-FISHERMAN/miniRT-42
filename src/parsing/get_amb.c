#include "parsing.h"

void	check_amb_range(t_minirt **minirt, char **str)
{
	if (ft_atof(str[1]) < 0.0 || ft_atof(str[1]) > 1.0)
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: Amb: "
			"Bad range for ambient\n[ambiente: >0.0/<1.0]", NULL},
			str[1]);
	check_rgb_range((char *[]){"miniRT", "parsing: Amb: "
		"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
		str[2], *minirt);
}

void	check_amb_format(t_minirt **minirt, char **str)
{
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: Amb: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [brightness: 0.0] [rgb: 0.0.0]\n");
	if (!only_double(str[1]) && !only_digit(str[1]))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Amb: Only brihtness ratio in double\n"
			"[ambiente: 0.0]", NULL}, str[1]);
	if (!only_digit_xyz(str[2], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Amb: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[2]);
}

void	get_amb(char **str, t_minirt **minirt)
{
	if ((*minirt)->amb)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one A accepted");
	check_amb_format(minirt, str);
	check_amb_range(minirt, str);
	(*minirt)->amb = ft_calloc(1, sizeof(t_amb));
	if (!(*minirt)->amb)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	(*minirt)->amb->light = ft_atof(str[1]);
	if (!ft_atoi_rgb(&(*minirt)->amb->rgb.r, &(*minirt)->amb->rgb.g, \
			&(*minirt)->amb->rgb.b, ft_split(str[2], ',')))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}
