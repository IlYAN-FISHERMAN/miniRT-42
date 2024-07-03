#include "objects.h"

bool	does_intersect(t_ray ray, t_scene *objects)
{
	t_object	*object;

	while (objects)
	{
		object = (t_object *)objects->content;
		if (object->does_intersect(ray, object))
			return (true);
		objects = objects->next;
	}
	return (false);
}

bool	intersect(t_intersect *intersect, t_scene *objects)
{
	bool		intersected;
	t_object	*object;

	intersected = false;
	while (objects)
	{
		object = (t_object *)objects->content;
		if (object->intersect(intersect, object))
			intersected = true;
		objects = objects->next;
	}
	return (intersected);
}
