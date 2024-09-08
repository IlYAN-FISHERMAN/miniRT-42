#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

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

int	check_standare_shape(t_minirt *minirt)
{
	if (!minirt->cam)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, \
			"No cam set");
	return (1);
}

void	check_error(int ac, char **av)
{
	if (ac <= 1 && printf("miniRT: Need <*.rt> file\n"))
		secure_exit(NULL);
	if ((!ft_strchr(av[1], '.') \
		|| ft_strncmp(ft_strchr(av[1], '.'), ".rt", 4))
		&& printf("miniRT: bad format file, only .rt file accepted\n"))
		exit(EXIT_FAILURE);
}
