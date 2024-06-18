#include "plane.h"

t_plane	*new_raw_plane(t_point origin, t_vector normal)
{
	t_plane	*plane;

	plane = galloc(sizeof(t_plane));
	if (!plane)
		return (0);
	plane->origin = origin;
	plane->normal = normal;
	return (plane);
}

t_object	*new_plane(t_point origin, t_vector normal)
{
	t_plane		*plane;
	t_object	*object;

	plane = new_raw_plane(origin, normal);
	if (!plane)
		return (0);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->type = plane;
	object->object = o_plane;
	return (object);
}
