/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:49:27 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:49:29 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "../miniRT.h"

void	process_camera(t_camera *camera)
{
	camera->aspect_ratio = camera->hsize / camera->vsize;
	camera->half_view = tan(camera->fov_rad * 0.5);
	if (camera->aspect_ratio >= 1)
	{
		camera->half_width = camera->half_view;
		camera->half_height = camera->half_view / camera->aspect_ratio;
	}
	else
	{
		camera->half_width = camera->half_view * camera->aspect_ratio;
		camera->half_height = camera->half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
	camera->c_origin = tm4mul(camera->inv_transform, point3(0, 0, 0));
}

t_camera	*new_camera(t_point3 origin, t_vector3 target, double fov)
{
	t_camera	*camera;
	t_minirt	*minirt;
	t_vector3	up_;

	origin.w = POINT;
	target.w = VECTOR;
	up_ = vector3(0, 1, 0);
	if (fabs(target.x) < EPSILOND && fabs(target.z) < EPSILOND)
	{
		up_ = vector3(0, 0, 1);
		if (target.y > 0)
			up_ = vector3(0, 0, -1);
	}
	camera = galloc(sizeof(t_camera));
	if (!camera)
		return (0);
	minirt = get_minirt();
	*camera = (t_camera){.origin = origin, .target = vnormalized(target),
		.fov = fov, .fov_rad = fov * DEG2RADF, .vsize = minirt->size->height,
		.hsize = minirt->size->width, .up = up_,
		.transform
		= view_transform(origin, vadd(origin, vnormalized(target)), up_)};
	camera->inv_transform = m4invert(camera->transform, 0);
	process_camera(camera);
	return (camera);
}

t_matrix4	view_transform(t_point3 from, t_point3 to, t_vector3 up)
{
	t_vector3	forward;
	t_vector3	left;
	t_vector3	true_up;
	t_matrix4	orientation;

	forward = vnormalized(vsub(to, from));
	left = vcross(forward, vnormalized(up));
	true_up = vcross(left, forward);
	orientation = (t_matrix4){.data = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}
	}};
	return (m4mul(orientation,
			m4translation(point3(-from.x, -from.y, -from.z))));
}

t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	double			w_x;
	double			w_y;
	t_vector3		direction;

	w_x = camera->half_width - ((x + 0.5) * camera->pixel_size);
	w_y = camera->half_height - ((y + 0.5) * camera->pixel_size);
	direction = vnormalized(vsub(tm4mul(camera->inv_transform,
					point3(w_x, w_y, -1)), camera->c_origin));
	return (ray(camera->c_origin, direction));
}
