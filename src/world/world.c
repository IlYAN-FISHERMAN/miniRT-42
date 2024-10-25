#include "world.h"

t_xs_parent	intersect_world(t_scene *scene, t_ray ray)
{
	t_object	*obj;
	t_xs_parent	xs_parent;

	xs_parent = xs();
	while (scene)
	{
		obj = scene->content;
		if (obj->type == o_light)
		{
			scene = scene->next;
			continue ;
		}
		xs_parent = mergef_intersections(xs_parent, intersect_at(obj, ray));
		scene = scene->next;
	}
	return (intersections(xs_parent));
}
