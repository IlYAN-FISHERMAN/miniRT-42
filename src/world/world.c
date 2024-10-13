#include "world.h"

t_scene	*dfworld(void)
{
	t_object	*s1;
	t_object	*s2;
	t_object	*l1;
	t_scene		*scene;

	s1 = new_sphere(point3(0, 0, 0), 1,
			color(byte_clamp(255 * 0.8), 255, byte_clamp(255 * 0.6)));
	s1->mat.diff = 0.7;
	s1->mat.spec = 0.2;
	s2 = new_sphere(point3(0, 0, 0), 1, color(255, 255, 255));
	set_transform(s2, m4scaling(vector3(0.5, 0.5, 0.5)));
	l1 = new_light(point3(-10, 10, -10), color(255, 255, 255), 1);
	scene = ft_lstnew(s1);
	ft_lstnew_back(scene, s2);
	ft_lstnew_back(scene, l1);
	return (scene);
}

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
