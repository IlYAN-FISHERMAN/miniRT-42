#include "colors.h"
#include "parsing.h"

void	check_pl_range(char **str, t_minirt *minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Pl: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	check_vector_range((char *[]){"miniRT", "parsing: Pl: "
		"Bad range for vector\n"
		"[vector : >-1.0/<1.0]", NULL}, str[2], minirt);
	check_rgb_range((char *[]){"miniRT", "parsing: Pl: "
		"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
		str[3], minirt);
	check_normal_range(minirt, str[2], "Pl");
}

void	check_pl_info(char **str, t_minirt *minirt)
{
	if ((BONUS && (ft_strlen_tab(str) < 4 || ft_strlen_tab(str) > 6))
		|| (!BONUS && (ft_strlen_tab(str) != 4)))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing: Pl: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [vector: 0.0,0.0,0.0]"
			" [rgb: 0.0.0] [material]x[bumpmap][optional])\n");
	if (!only_double_xyz(str[1], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Pl: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double_xyz(str[2], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Pl: Bad vector format\n"
			"[vector: 0.0,0.0,0.0]", NULL}, str[2]);
	if (!only_digit_xyz(str[3], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Cy: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[3]);
}

static void	check_pl_material(char **str, t_minirt **minirt,
							t_object *obj, t_color color)
{
	t_define	*dif;

	if (BONUS && ft_strlen_tab(str) > 4 && str[4])
	{
		if (str[4] && is_dfmat(str[4]))
			obj->mat = get_dfmat(str[4], color, *minirt);
		else if (str[4] && is_define(str[4], (*minirt)->mat))
			obj->mat = get_define_mat(str[4], (*minirt)->mat, color);
		else if (str[4])
			crash_exit(*minirt, (char *[]){"miniRT", "Material: Cy: Bad "
				"format\nunknown material", NULL}, str[4]);
		if (str[5])
		{
			check_bumpmap_error(str[5], *minirt);
			dif = ft_calloc(1, sizeof(t_define));
			if (!dif)
				crash_exit(*minirt,
					(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
			dif->mat.bumpmap = load_bumpmap(str[5]);
			obj->mat.bumpmap = dif->mat.bumpmap;
			ft_lstnew_back(&(*minirt)->mat, dif);
		}
	}
}

void	get_pl(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	t_color		color;
	t_point3	origin;
	t_vector3	normal;

	check_pl_info(str, *minirt);
	check_pl_range(str, *minirt);
	scene = get_scene_struct(minirt);
	origin.w = POINT;
	normal.w = VECTOR;
	ft_atof_xyz(&origin.x, &origin.y, &origin.z,
		ft_split(str[1], ','));
	ft_atof_xyz(&normal.x, &normal.y, &normal.z,
		ft_split(str[2], ','));
	if (!ft_atoi_rgb(&color.r, &color.g, &color.b,
			ft_split(str[3], ',')))
		crash_exit(*minirt, (char *[]){"miniRT",
			"parsing: pl bad number format", NULL}, str[3]);
	scene->content = new_plane(origin, normal, color);
	if (!scene->content)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	check_pl_material(str, minirt, scene->content, color);
	ft_lstadd_back(&(*minirt)->world.scene, scene);
}
