#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

void	check_size_format(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"too many information with R");
	if ((!only_digit(str[1])) || (!only_digit(str[2])))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "R: only digit accepted");
	if ((ft_atoi(str[1]) > 7680 || ft_atoi(str[1]) < 100)
		|| (ft_atoi(str[2]) > 7680 || ft_atoi(str[1]) < 100))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "R: range >100/<7680");
}

void	get_size(char **str, t_minirt **minirt)
{
	if ((*minirt)->size)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one R accepted");
	check_size_format(str, minirt);
	(*minirt)->size = new_image(ft_atoi(str[1]), ft_atoi(str[2]));
	if (!(*minirt)->size)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}
