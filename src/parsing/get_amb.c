#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

void	check_amb_format(t_minirt **minirt, char **str)
{
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "L number of arg");
	if (!only_float(str[1]) && !only_digit(str[1]))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing", NULL},
			"Amb, only ambient ratio in float");
	if (!only_digit_xyz(str[2], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing", NULL},
			"Amb, rgb bad format");
}

void	get_amb(char **str, t_minirt **minirt)
{
	char	**split;

	if ((*minirt)->amb)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one A accepted");
	check_amb_format(minirt, str);
	split = ft_split(str[2], ',');
	if (!split)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	(*minirt)->amb = ft_calloc(1, sizeof(t_amb));
	if (!(*minirt)->amb)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	(*minirt)->amb->light = ft_atof(str[1]);
	(*minirt)->amb->rgb.r = ft_atoi(split[0]);
	(*minirt)->amb->rgb.g = ft_atoi(split[1]);
	(*minirt)->amb->rgb.b = ft_atoi(split[2]);
	ft_free_tab(split);
}
