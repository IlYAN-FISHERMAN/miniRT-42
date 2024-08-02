#include "objects.h"

bool	does_intersect(t_ray ray, t_scene *objects)
{
	t_object	*object;

	while (objects)
	{
		object = (t_object *)objects->content;
		if (object->type == o_light)
		{
			objects = objects->next;
			continue ;
		}
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
		if (object->type == o_light)
		{
			objects = objects->next;
			continue ;
		}
		if (object->intersect(intersect, object))
		{
			intersected = true;
			intersect->position = vadd(intersect->ray.origin,
					vmul(intersect->ray.direction, intersect->t));
			intersect->normal = object->normal_at(object, intersect->position);
		}
		objects = objects->next;
	}
	return (intersected);
}
