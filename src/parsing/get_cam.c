#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

void	check_cam_format(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "C bad format");
	if (!only_float_xyz(str[1], *minirt))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: only float accepted", NULL}, str[1]);
	if (!only_float_xyz(str[2], *minirt))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: only float accepted", NULL}, str[2]);
	if (!only_digit(str[3]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: only digit accepted", NULL}, str[3]);
	if (ft_atoi(str[3]) > 180 || ft_atoi(str[3]) < 0)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL},
			"Cam: bad number >0/<180");
}

void	get_cam_info(t_point3 *origin, t_vector3 *target,
				t_minirt *minirt, char **str)
{
	if (!ft_atof_xyz(&origin->x, &origin->y, &origin->z, ft_split(str[1], ',')))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "ft_atof_xyz failed");
	if (!ft_atof_xyz(&target->x, &target->y, &target->z, ft_split(str[2], ',')))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "ft_atof_xyz failed");
}

void	get_cam(char **str, t_minirt **minirt)
{
	t_point3	origin;
	t_vector3	target;

	if ((*minirt)->cam)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one C accepted");
	check_cam_format(str, minirt);
	get_cam_info(&origin, &target, *minirt, str);
	if ((*minirt)->size)
		(*minirt)->cam = new_camera(origin, target, ft_atof(str[3]),
				(float)((*minirt)->size->width / (*minirt)->size->height));
	else
		(*minirt)->cam = new_camera(origin, target, ft_atof(str[3]),
				(float)WIDTH / HEIGHT);
	if (!(*minirt)->cam)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}
