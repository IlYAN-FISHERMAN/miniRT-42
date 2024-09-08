#include "parsing.h"

void	check_size_format(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) != 3)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: R: bad number of arg", NULL}, \
			"\n[Height: 1920] [Width: 1080]\n");
	if (!only_digit(str[1]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: \n"
			"R: only digit accepted", NULL}, str[1]);
	if (!only_digit(str[2]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: \n"
			"R: only digit accepted", NULL}, str[2]);
	if (ft_atoi(str[1]) > 7680 || ft_atoi(str[1]) < 100)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: "
			"R: bad range for window\n[Size >100/<7680]", NULL}, str[1]);
	if (ft_atoi(str[2]) > 7680 || ft_atoi(str[2]) < 100)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: "
			"R: bad range for window\n[Size >100/<7680]", NULL}, str[2]);
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
