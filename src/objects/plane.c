#include "plane.h"

//  intersect_plane: Check if ray intersects plane
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the plane, false otherwise
static t_xs	intersect_plane(t_object *object, t_ray ray)
{
	t_xs	xs;

	ft_bzero(&xs, sizeof(t_xs));
	(void)object;
	(void)ray;
	return (xs);
}

//  normal_at_plane: Get the normal at a point on the plane
//  @param object The object
//  @param world_point The point on the plane
//  @return The normal at the point
static t_vector3	normal_at_plane(t_object *object, t_point3 world_point)
{
	t_vector3	v;

	ft_bzero(&v, sizeof(t_vector3));
	(void)object;
	(void)world_point;
	return (v);
}

t_object	*new_plane(t_point3 origin, t_vector3 normal, t_color color)
{
	t_object	*object;

	origin.w = POINT;
	normal.w = VECTOR;
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_plane));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	*((t_plane *)object->data) = (t_plane){.origin = origin,
		.normal = normal, .color = color};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.transform = m4default(), .intersect = intersect_plane,
		.type = o_plane, .normal_at = normal_at_plane};
	return (object);
}
