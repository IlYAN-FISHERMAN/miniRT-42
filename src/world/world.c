#include "world.h"

t_xs_parent	intersect_world(t_scene *scene, t_ray ray)
{
	t_xs_parent	xs_parent;

	xs_parent = xs();
	while (scene)
	{
		xs_parent = mergef_intersections(xs_parent,
				intersect_at(scene->content, ray));
		scene = scene->next;
	}
	return (intersections(xs_parent));
}
