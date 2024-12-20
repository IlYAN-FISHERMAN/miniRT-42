/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:43:17 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:43:18 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_cam_range(char **str, t_minirt **minirt)
{
	check_xyz_range((char *[]){"miniRT", "parsing: Cam: "
		"Bad range for xyz position\n"
		"[xyz : >-10 000/<10 000]", NULL}, str[1], *minirt);
	check_vector_range((char *[]){"miniRT", "parsing: Cam: "
		"Bad range for vector\n"
		"[vector : >-1.0/<1.0]", NULL}, str[2], *minirt);
	if (ft_atoi(str[3]) < 0 || ft_atoi(str[3]) > 180)
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: Cam: "
			"Bad range for fov\n[fov: >0/<180]", NULL},
			str[3]);
	check_normal_range(*minirt, str[2], "Cam");
}

void	check_cam_format(char **str, t_minirt **minirt)
{
	if (ft_strlen_tab(str) != 4)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing: Cam: bad number of arg", NULL}, \
			"\n[xyz: 0.0,0.0,0.0] [vector: 0.0,0.0,0.0] [fov: 0]\n");
	if (!only_double_xyz(str[1], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Cam: Bad xyz format\n"
			"[xyz: 0.0,0.0,0.0]", NULL}, str[1]);
	if (!only_double_xyz(str[2], *minirt))
		crash_exit(*minirt, (char *[]){"miniRT", "parsing: "
			"Cam: Bad vector format\n"
			"[vector: 0.0,0.0,0.0]", NULL}, str[2]);
	if (!only_digit(str[3]))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing",
			"Cam: Bad fov format\n"
			"[fov: >0/<180]", NULL}, str[3]);
}

void	get_cam(char **str, t_minirt **minirt)
{
	t_point3	origin;
	t_vector3	target;

	if ((*minirt)->world.cam)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Only one C accepted");
	check_cam_format(str, minirt);
	check_cam_range(str, minirt);
	origin.w = POINT;
	target.w = VECTOR;
	if (!ft_atof_xyz(&origin.x, &origin.y, &origin.z, ft_split(str[1], ','))
		|| !ft_atof_xyz(&target.x, &target.y, &target.z, ft_split(str[2], ',')))
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	if ((*minirt)->size)
		(*minirt)->world.cam = new_camera(origin, target, ft_atof(str[3]));
	else
		(*minirt)->world.cam = new_camera(origin, target, ft_atof(str[3]));
	if (!(*minirt)->world.cam)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
}
