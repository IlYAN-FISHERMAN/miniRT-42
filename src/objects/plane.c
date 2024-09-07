#include "plane.h"

t_plane	*new_raw_plane(t_point3 origin, t_vector3 normal, t_color color)
{
	t_plane	*plane;

	plane = galloc(sizeof(t_plane));
	if (!plane)
		return (0);
	plane->origin = origin;
	plane->normal = normal;
	plane->color = color;
	return (plane);
}

t_object	*new_plane(t_point3 origin, t_vector3 normal, t_color color)
{
	t_plane		*plane;
	t_object	*object;

	plane = new_raw_plane(origin, normal, color);
	if (!plane)
		return (0);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->type = o_plane;
	object->data = plane;
	object->intersect = intersect_plane;
	object->does_intersect = does_intersect_plane;
	return (object);
}

bool	intersect_plane(t_intersect *intersect, t_object *object)
{
	t_plane	*plane;
	double	dotn;
	double	t;

	plane = (t_plane *)object->data;
	dotn = vdot(intersect->ray.direction, plane->normal);
	if (dotn == 0.0f)
		return (false);
	t = vdot(vsub(plane->origin, intersect->ray.origin), plane->normal) / dotn;
	if (t <= RAY_T_MIN || t >= intersect->t)
		return (false);
	intersect->t = t;
	intersect->object = object;
	intersect->color = plane->color;
	return (true);
}

bool	does_intersect_plane(t_ray ray, t_object *object)
{
	t_plane	*plane;
	double	dotn;
	double	t;

	plane = (t_plane *)object->data;
	dotn = vdot(ray.direction, plane->normal);
	if (dotn == 0.0f)
		return (false);
	t = vdot(vsub(plane->origin, ray.origin), plane->normal) / dotn;
	if (t <= RAY_T_MIN || t >= RAY_T_MAX)
		return (false);
	return (true);
}
