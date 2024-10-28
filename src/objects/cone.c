/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:11 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:12 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

//  quadratic_cone: Calculate the quadratic formula for the cone
//  @param r The ray
//  @return The quadratic formula
static t_calc_cone	quadratic_cone(t_ray r)
{
	t_calc_cone	c;
	double		inv_a;

	c.a = r.direction.x * r.direction.x - r.direction.y * r.direction.y
		+ r.direction.z * r.direction.z;
	c.b = 2 * r.origin.x * r.direction.x - 2 * r.origin.y * r.direction.y
		+ 2 * r.origin.z * r.direction.z;
	c.c = r.origin.x * r.origin.x - r.origin.y * r.origin.y
		+ r.origin.z * r.origin.z;
	if (ft_equalsd(c.a, 0))
		return (c);
	c.discriminant = c.b * c.b - 4 * c.a * c.c;
	if (fabs(c.a) < EPSILOND || c.discriminant < -EPSILOND)
		return (c);
	c.disc_sqrt = sqrt(c.discriminant);
	inv_a = 1 / (2 * c.a);
	c.t[0] = (-c.b - c.disc_sqrt) * inv_a;
	c.t[1] = (-c.b + c.disc_sqrt) * inv_a;
	c.y[0] = r.origin.y + c.t[0] * r.direction.y;
	c.y[1] = r.origin.y + c.t[1] * r.direction.y;
	return (c);
}

//	base_cone_inter: Check if ray intersects the base of the cone
//	@param r The ray
//	@param inters The intersection data
//	@param obj The object to check
static void	base_cone_inter(t_ray r, t_xs_parent *inters, t_object *obj)
{
	double		t;
	double		x_base;
	double		z_base;

	if (ft_equalsd(r.direction.y, 0))
		return ;
	t = (1 - r.origin.y) / r.direction.y;
	x_base = r.origin.x + t * r.direction.x;
	z_base = r.origin.z + t * r.direction.z;
	if (x_base * x_base + z_base * z_base <= 1)
		add_intersection(inters, intersection(t, obj));
}

//  intersect_cone: Check if ray intersects cone
//  @param intersect The intersection data
//  @param obj The object to check
//  @return true if the ray intersects the cone, false otherwise
static t_xs_parent	intersect_cone(t_object *obj, t_ray r)
{
	t_xs_parent	inters;
	t_calc_cone	c;

	inters = xs();
	c = quadratic_cone(r);
	if (ft_equalsd(c.a, 0))
	{
		if (ft_equalsd(c.b, 0))
			return (inters);
		add_intersection(&inters, intersection(-c.c / (2 * c.b), obj));
		return (inters);
	}
	if (c.discriminant < -EPSILOND || fabs(c.a) < EPSILOND)
		return (inters);
	if (c.y[0] > 0 && c.y[0] < 1 - EPSILOND)
		add_intersection(&inters, intersection(c.t[0], obj));
	if (c.y[1] > 0 && c.y[1] < 1 - EPSILOND)
		add_intersection(&inters, intersection(c.t[1], obj));
	base_cone_inter(r, &inters, obj);
	return (inters);
}

//  normal_at_cone: Get the normal at a point on the cone
//  @param obj The object
//  @param local_point The point on the cone
//  @return The normal at the point
static t_vector3	normal_at_cone(t_object *obj, t_point3 lp)
{
	t_vector3	normal;
	double		dist;
	t_vector2	uv;
	bool		is_caps;

	is_caps = true;
	dist = lp.x * lp.x + lp.z * lp.z;
	if (dist < 1 - EPSILOND && lp.y >= 1 - EPSILOND)
		normal = vector3(0, 1, 0);
	else if (dist < 1 - EPSILOND && lp.y <= EPSILOND)
		normal = vector3(0, -1, 0);
	else
	{
		is_caps = false;
		normal = vnormalized(vector3(lp.x, -sqrt(dist), lp.z));
	}
	if (obj->mat.bumpmap)
	{
		uv = uv_mapping_cone(lp, is_caps);
		normal = perturbn(normal, get_bumpv(obj->mat.bumpmap, uv));
	}
	return (normal);
}

t_object	*new_cone(t_point3 origin, double *rad_hei,
				t_vector3 normal, t_color color)
{
	t_object	*obj;

	origin.w = POINT;
	normal.w = VECTOR;
	vnormalize(&normal);
	obj = galloc(sizeof(t_object));
	if (!obj)
		return (0);
	obj->data = galloc(sizeof(t_cone));
	if (!obj->data)
	{
		gfree(obj);
		return (0);
	}
	*((t_cone *)obj->data) = (t_cone){.origin = origin,
		.radius = rad_hei[0], .height = rad_hei[1], .normal = normal};
	*obj = (t_object){.data = obj->data, .mat = dfmaterial(color),
		.transform = m4translation(origin), .local_intersect = intersect_cone,
		.type = o_cone, .local_normal_at = normal_at_cone};
	set_transform(obj, m4rotating_dir(point3(0, 1, 0), normal));
	set_transform(obj,
		m4scaling(vector3(rad_hei[0], rad_hei[1], rad_hei[0])));
	obj->inv_transform = m4invert(obj->transform, 0);
	obj->tinv_transform = m4transpose(obj->inv_transform);
	return (obj);
}
