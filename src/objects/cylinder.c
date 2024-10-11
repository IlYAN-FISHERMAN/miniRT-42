#include "cylinder.h"

//  intersect_cylinder: Check if ray intersects cylinder and update
//  intersection data
//  @param intersect The intersection data
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the cylinder, false otherwise
t_xs	intersect_cylinder(t_object *object, t_ray ray)
{
	t_xs	xs;

	ft_bzero(&xs, sizeof(t_xs));
	(void)object;
	(void)ray;
	return (xs);
}

//  normal_at_cylinder: Get the normal at a point on the cylinder
//  @param object The object
//  @param world_point The point on the cylinder
//  @return The normal at the point
t_vector3	normal_at_cylinder(t_object *object, t_point3 world_point)
{
	t_vector3	v;

	ft_bzero(&v, sizeof(t_vector3));
	(void)object;
	(void)world_point;
	return (v);
}

t_object	*new_cylinder(t_point3 origin, float *rad_hei,
				t_vector3 normal, t_color color)
{
	t_object	*object;

	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_cylin));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	*((t_cylin *)object->data) = (t_cylin){.origin = origin,
		.radius = rad_hei[0], .height = rad_hei[1], .normal = normal};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.transform = m4default(), .intersect = intersect_cylinder,
		.type = o_cylin, .normal_at = normal_at_cylinder};
	return (object);
}
