#include "parsing.h"

void	check_xyz_range(char **context, char *str, t_minirt *minirt)
{
	double	x;
	double	y;
	double	z;

	if (!ft_atof_xyz(&x, &y, &z, ft_split(str, ',')))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	if (x < -10000.0 || x > 10000.0
		|| y < -10000.0 || y > 10000.0
		|| z < -10000.0 || z > 10000.0)
		crash_exit(minirt, context, str);
}

void	check_vector_range(char **context, char *str, t_minirt *minirt)
{
	double	x;
	double	y;
	double	z;

	if (!ft_atof_xyz(&x, &y, &z, ft_split(str, ',')))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	if (x < -1.0 || x > 1.0
		|| y < -1.0 || y > 1.0
		|| z < -1.0 || z > 1.0)
		crash_exit(minirt, context, str);
}

void	check_rgb_range(char **context, char *str, t_minirt *minirt)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	if (ft_atoi(split[0]) < 0 || ft_atoi(split[0]) > 255
		|| ft_atoi(split[1]) < 0 || ft_atoi(split[1]) > 255
		|| ft_atoi(split[2]) < 0 || ft_atoi(split[2]) > 255)
		crash_exit(minirt, context, str);
	ft_free_tab(split);
}
