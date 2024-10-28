/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:19 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:20 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

//  base_cylinder_inter: Check if ray intersects the base of the cylinder
//  @param r The ray
//  @param inters The intersection data
//  @param obj The object to check
static void	base_cylinder_inter(t_ray r, t_xs_parent *inters, t_object *obj)
{
	double		t;
	double		x_base;
	double		z_base;

	if (ft_equalsd(r.direction.y, 0))
		return ;
	t = (-0.5 - r.origin.y) / r.direction.y;
	x_base = r.origin.x + t * r.direction.x;
	z_base = r.origin.z + t * r.direction.z;
	if (x_base * x_base + z_base * z_base <= 1)
		add_intersection(inters, intersection(t, obj));
	t = (0.5 - r.origin.y) / r.direction.y;
	x_base = r.origin.x + t * r.direction.x;
	z_base = r.origin.z + t * r.direction.z;
	if (x_base * x_base + z_base * z_base <= 1)
		add_intersection(inters, intersection(t, obj));
}

//  intersect_cylinder: Check if ray intersects cylinder
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the cylinder, false otherwise
static t_xs_parent	intersect_cylinder(t_object *object, t_ray r)
{
	t_xs_parent		inters;
	t_calc_cylin	c;
	double			inv_a;

	inters = xs();
	c.a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	c.b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c.c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	c.discriminant = c.b * c.b - 4 * c.a * c.c;
	if (fabs(c.a) < EPSILOND || c.discriminant < -EPSILOND)
		return (inters);
	c.disc_sqrt = sqrt(c.discriminant);
	inv_a = 1 / (2 * c.a);
	c.t[0] = (-c.b - c.disc_sqrt) * inv_a;
	c.t[1] = (-c.b + c.disc_sqrt) * inv_a;
	c.y[0] = r.origin.y + c.t[0] * r.direction.y;
	c.y[1] = r.origin.y + c.t[1] * r.direction.y;
	c.does_inter[0] = ((c.y[0] >= -0.5) && (c.y[0] <= 0.5));
	c.does_inter[1] = ((c.y[1] >= -0.5) && (c.y[1] <= 0.5));
	if (c.does_inter[0])
		add_intersection(&inters, intersection(c.t[0], object));
	if (c.does_inter[1])
		add_intersection(&inters, intersection(c.t[1], object));
	base_cylinder_inter(r, &inters, object);
	return (inters);
}

//  uv_mapping_cyl: Map a point on the cylinder to a 2D UV coordinate
//  @param local_point The point on the cylinder
//  @param is_caps True if the point is on the caps, false otherwise
//  @return The UV coordinate
static t_vector2	uv_mapping_cyl(t_point3 local_point, bool is_caps)
{
	double	theta;
	double	u;
	double	v;

	if (!is_caps)
	{
		theta = atan2(local_point.x, local_point.z);
		u = (theta + M_PI) / (2 * M_PI);
		v = (local_point.y + 0.5);
	}
	else
	{
		u = (local_point.x + 1) * 0.5;
		v = (local_point.z + 1) * 0.5;
	}
	return (vector2(u, v));
}

//  normal_at_cylinder: Get the normal at a point on the cylinder
//  @param object The object
//  @param local_point The point on the cylinder
//  @return The normal at the point
static t_vector3	normal_at_cylinder(t_object *object, t_point3 local_point)
{
	t_vector3		normal;
	bool			is_caps;

	is_caps = true;
	(void)object;
	if (local_point.y >= 0.5 - EPSILOND)
		normal = vector3(0, 1, 0);
	else if (local_point.y <= -0.5 + EPSILOND)
		normal = vector3(0, -1, 0);
	else
	{
		is_caps = false;
		normal = vector3(local_point.x, 0, local_point.z);
	}
	if (object->mat.bumpmap)
		normal = perturbn(normal,
				get_bumpv(object->mat.bumpmap,
					uv_mapping_cyl(local_point, is_caps)));
	return (normal);
}

t_object	*new_cylinder(t_point3 origin, double *rad_hei,
				t_vector3 normal, t_color color)
{
	t_object	*object;

	origin.w = POINT;
	normal.w = VECTOR;
	vnormalize(&normal);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_cylin));
	if (!object->data)
		gfree(object);
	if (!object->data)
		return (0);
	*((t_cylin *)object->data) = (t_cylin){.origin = origin,
		.radius = rad_hei[0], .height = rad_hei[1], .normal = normal};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.transform = m4translation(origin),
		.local_intersect = intersect_cylinder,
		.type = o_cylin, .local_normal_at = normal_at_cylinder};
	set_transform(object, m4rotating_dir(point3(0, 1, 0), normal));
	set_transform(object,
		m4scaling(vector3(rad_hei[0], rad_hei[1], rad_hei[0])));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
