#include "parsing.h"

static void	check_co_range(char **str, t_minirt *minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Co: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	check_vector_range((char *[]){"miniRT", "parsing: Co: "
		"Bad range for vector\n"
		"[vector : >-1.0/<1.0]", NULL}, str[2], minirt);
	if (ft_atof(str[3]) < -10000.0 || ft_atof(str[3]) > 10000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Co: "
			"Bad range for radius\n[radius: >-10k.0/<10k.0]", NULL},
			str[3]);
	if (ft_atof(str[4]) < -10000.0 || ft_atof(str[4]) > 10000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Co: "
			"Bad range for height\n[height: >-10k.0/<10k.0]", NULL}, str[4]);
	check_rgb_range((char *[]){"miniRT", "parsing: Co: "
		"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
		str[5], minirt);
}

static void	check_co_material(char **str, t_minirt **minirt,
							t_object *obj, t_color color)
{
	if (BONUS && ft_strlen_tab(str) > 6 && str[6])
	{
		if (str[6] && is_dfmat(str[6]))
			obj->mat = get_dfmat(str[6], color, *minirt);
		else if (str[6] && is_define(str[6], (*minirt)->mat))
			obj->mat = get_define_mat(str[6], (*minirt)->mat, color);
		else if (str[6])
			crash_exit(*minirt, (char *[]){"miniRT", "Material: Co: Bad "
				"format\nunknown material", NULL}, str[6]);
		if (str[7])
		{
			check_bumpmap_error(str[7], *minirt);
			obj->mat.bumpmap = load_bumpmap(str[7]);
		}
	}
}

static void	check_co_info(char **str, t_minirt *minirt)
{
	if ((BONUS && (ft_strlen_tab(str) < 6 || ft_strlen_tab(str) > 8))
		|| (!BONUS && (ft_strlen_tab(str) != 6)))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing: Co: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [vector: 0.0,0.0,0.0]"
			" [radius: 0.0] [height: 0.0] [rgb: 0.0.0] "
			"[material]x[bumpmap][optional])\n");
	if (!only_double_xyz(str[1], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Co: Bad xyz "
			"format\n[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double_xyz(str[2], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Co: Bad vector "
			"format\n[vector: 0.0,0.0,0.0]", NULL}, str[2]);
	if (!only_double(str[3]) && !only_digit(str[3]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Co: Bad "
			"radius format\n[radius: 0.0]", NULL}, str[3]);
	if (!only_double(str[4]) && !only_digit(str[4]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Co: Bad "
			"height format\n[height: 0.0]", NULL}, str[4]);
	if (!only_digit_xyz(str[5], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Co: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[5]);
}

void	get_co(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	double		rad_hei[2];
	t_vector3	normal;
	t_point3	origin;
	t_color		color;

	check_co_info(str, *minirt);
	check_co_range(str, *minirt);
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
	scene->content = new_cone(origin, rad_hei, normal, color);
	if (!((t_object *)scene->content))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	check_co_material(str, minirt, scene->content, color);
	ft_lstadd_back(&(*minirt)->world.scene, scene);
}
