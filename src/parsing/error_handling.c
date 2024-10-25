#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"
#include "ft_string.h"

int	correct_dl(char *gnl)
{
	if (ft_strchr(gnl, '\n'))
		gnl[ft_strlen(gnl) - 1] = '\0';
	return (1);
}

void	get_size_default(t_minirt **minirt)
{
	(*minirt)->size = new_image(WIDTH, HEIGHT);
	if (!(*minirt)->size)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}

int	check_standard_shape(t_minirt *minirt)
{
	if (!minirt->world.cam)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, \
			"No cam set");
	return (1);
}

void	check_error(int ac, char **av, t_minirt *minirt)
{
	if (ac > 2)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, \
			"Too much information");
	if (ac < 2)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", "No enough information", NULL},
			"\nTry './miniRT -h' for help.");
	if (!ft_strcmp(av[1], "-h") || !ft_strcmp(av[1], "-help"))
		help_message(minirt);
	else if (!ft_strcmp(av[1], "-random") || !ft_strcmp(av[1], "-r"))
		minirt->fd = rt_generator("1000", "1000", BONUS);
	else if (!ft_strrchr(av[1], '.')
		|| ft_strncmp(ft_strrchr(av[1], '.'), ".rt", 4))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Need *.rt file");
	else
		minirt->fd = open(av[1], O_RDONLY);
	if (minirt->fd == -1)
		crash_exit(minirt, \
			(char *[]){"miniRT", av[1], NULL}, "No such file or directory");
}
