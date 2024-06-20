#include "objects.h"

bool	does_intersect(t_intersect *intersect, t_objects *objects)
{
	bool	intersected;

	intersected = false;
	while (objects)
	{
		if (objects->content->intersect(intersect, objects->content))
			intersected = true;
		objects = objects->next;
	}
	return (intersected);
}

bool	intersect(t_ray ray, t_objects *objects)
{
	while (objects)
	{
		if (objects->content->does_intersect(ray, objects->content))
			return (true);
		objects = objects->next;
	}
}
