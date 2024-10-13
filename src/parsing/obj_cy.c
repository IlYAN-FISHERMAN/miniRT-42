#include "parsing.h"

void	check_cy_range(char **str, t_minirt *minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Cy: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	check_vector_range((char *[]){"miniRT", "parsing: Cy: "
		"Bad range for vector\n"
		"[vector : >-1.0/<1.0]", NULL}, str[2], minirt);
	if (ft_atof(str[3]) < -10000.0 || ft_atof(str[3]) > 10000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Cy: "
			"Bad range for radius\n[radius: >-10k.0/<10k.0]", NULL},
			str[3]);
	if (ft_atof(str[4]) < -10000.0 || ft_atof(str[4]) > 10000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Cy: "
			"Bad range for height\n[height: >-10k.0/<10k.0]", NULL}, str[4]);
	check_rgb_range((char *[]){"miniRT", "parsing: Cy: "
		"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
		str[5], minirt);
}

void	check_cy_info(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) != 6)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing: Cy: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [vector: 0.0,0.0,0.0]"
			" [radius: 0.0] [height: 0.0] [rgb: 0.0.0]\n");
	if (!only_double_xyz(str[1], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Cy: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double_xyz(str[2], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Cy: Bad vector "
			"format\n[vector: 0.0,0.0,0.0]", NULL}, str[2]);
	if (!only_double(str[3]) && !only_digit(str[3]))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", "Cy: Bad radius format\n"
			"[radius: 0.0]", NULL}, str[3]);
	if (!only_double(str[4]) && !only_digit(str[4]))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", "Cy: Bad height format\n"
			"[height: 0.0]", NULL}, str[4]);
	if (!only_digit_xyz(str[5], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Cy: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[5]);
}

void	get_cy(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	double		rad_hei[2];
	t_vector3	normal;
	t_point3	origin;
	t_color		color;

	check_cy_info(str, *minirt);
	check_cy_range(str, *minirt);
	scene = get_scene_struct(minirt);
	ft_atof_xyz(&origin.x, &origin.y, &origin.z,
		ft_split(str[1], ','));
	ft_atof_xyz(&normal.x, &normal.y, &normal.z,
		ft_split(str[2], ','));
	if (!ft_atoi_rgb(&color.r, &color.g, &color.b,
			ft_split(str[5], ',')))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	rad_hei[0] = ft_atof(str[3]) * 0.5;
	rad_hei[1] = ft_atof(str[4]);
	scene->content = new_cylinder(origin, rad_hei, normal, color);
	if (!((t_object *)scene->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	ft_lstadd_back(&(*minirt)->scene, scene);
}
