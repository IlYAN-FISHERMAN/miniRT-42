#include "sphere.h"

t_sphere	*new_raw_sphere(t_point origin, double radius)
{
	t_sphere	*sphere;

	sphere = galloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	sphere->origin = origin;
	sphere->radius = radius;
	return (sphere);
}

t_object	*new_sphere(t_point origin, double radius)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = new_raw_sphere(origin, radius);
	if (!sphere)
		return (0);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->type = o_sphere;
	object->data = sphere;
	return (object);
}
