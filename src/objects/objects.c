/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:53 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:54 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "material.h"

t_vector3	normal_at(t_object *obj, t_point3 world_point)
{
	t_point3	local_point;
	t_vector3	local_normal;
	t_vector3	world_normal;

	local_point = tm4mul(obj->inv_transform, world_point);
	local_normal = obj->local_normal_at(obj, local_point);
	world_normal = tm4mul(obj->tinv_transform, local_normal);
	world_normal.w = VECTOR;
	vnormalize(&world_normal);
	return (world_normal);
}

t_xs_parent	intersect_at(t_object *obj, t_ray ray)
{
	return (obj->local_intersect(obj, transform(ray, obj->inv_transform)));
}

t_mat	dfmaterial(t_color color)
{
	return (mat_mat(color));
}

void	set_transform(t_object *obj, t_matrix4 transform)
{
	obj->transform = m4mul(obj->transform, transform);
}
