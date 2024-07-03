#include "objects.h"

bool	does_intersect(t_intersect *intersect, t_objects *objects)
{
	bool		intersected;
	t_object	*object;

	intersected = false;
	while (objects)
	{
		object = objects->content;
		if (object->intersect(intersect, objects->content))
			intersected = true;
		objects = objects->next;
	}
	return (intersected);
}

bool	intersect(t_ray ray, t_objects *objects)
{
	t_object	*object;

	while (objects)
	{
		object = objects->content;
		if (object->does_intersect(ray, objects->content))
			return (true);
		objects = objects->next;
	}
	return (false);
}
