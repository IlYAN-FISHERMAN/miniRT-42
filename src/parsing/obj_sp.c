/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:43:41 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:43:42 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_sp_range(char **str, t_minirt *minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Sp: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], minirt);
	if (ft_atof(str[2]) < 0.1 || ft_atof(str[2]) > 10000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Sp: "
			"Bad range for diameter\n[diam: >0.1/<10k.0]", NULL},
			str[2]);
	check_rgb_range((char *[]){"miniRT", "parsing: Sp: "
		"Bad range for rgb\n[rgb: >0/<255]", NULL}, \
		str[3], minirt);
}

static void	check_sp_material(char **str, t_minirt **minirt,
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
			crash_exit(*minirt, (char *[]){"miniRT", "Material: Sp: Bad "
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

void	check_sp_info(char **str, t_minirt *minirt)
{
	if ((BONUS && (ft_strlen_tab(str) < 4 || ft_strlen_tab(str) > 6))
		|| (!BONUS && (ft_strlen_tab(str) != 4)))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing: Sp: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [radius: 0.0] [rgb: 0.0.0]"
			" [material]x[bumpmap][optional])\n");
	if (!only_double_xyz(str[1], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Sp: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double(str[2]) && !only_digit(str[2]))
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", "Sp: Bad radius format\n"
			"[radius: 0.0]", NULL}, str[2]);
	if (!only_digit_xyz(str[3], minirt))
		crash_exit(minirt, (char *[]){"miniRT", "parsing: "
			"Sp: Bad rgb format\n"
			"[rgb: 0,0,0]", NULL}, str[3]);
}

void	get_sp(char **str, t_minirt **minirt)
{
	t_scene		*scene;
	t_point3	origin;
	t_color		color;

	check_sp_info(str, *minirt);
	check_sp_range(str, *minirt);
	scene = get_scene_struct(minirt);
	ft_atof_xyz(&origin.x, &origin.y, &origin.z,
		ft_split(str[1], ','));
	if (!ft_atoi_rgb(&color.r, &color.g, &color.b,
			ft_split(str[3], ',')))
		crash_exit(*minirt,
			(char *[]){"miniRT",
			"parsing: sp bad rgb format", NULL}, str[3]);
	scene->content = new_sphere(origin, ft_atof(str[2]) * 0.5, color);
	if (!scene->content)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	check_sp_material(str, minirt, scene->content, color);
	ft_lstadd_back(&(*minirt)->world.scene, scene);
}
