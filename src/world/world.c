#include "world.h"

t_object	*get_next_light(t_scene *scene)
{
	static t_scene	*current;
	t_object		*light;

	if (!current)
		current = scene;
	while (current)
	{
		if (((t_object *)current->content)->type == o_light)
		{
			light = current->content;
			current = current->next;
			return (light);
		}
		current = current->next;
	}
	return (0);
}

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
		xs_parent = mergef_intersections(xs_parent, obj->intersect(obj, ray));
		scene = scene->next;
	}
	return (intersections(xs_parent));
}
