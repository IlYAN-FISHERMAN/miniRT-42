#include "lightning.h"
#include "../world/world.h"

bool	is_shadowed(t_scene *scene, t_point3 point, t_object *light)
{
	t_vector3	v;
	t_xs_parent	xs_parent;
	t_intersect	*i;
	t_ray		r;

	v = vsub(((t_light *)light->data)->pos, point);
	r = ray(point, vnormalized(v));
	xs_parent = intersect_world(scene, r);
	i = hit(xs_parent);
	if (i && i->t < sqrt(vlength2(v)))
	{
		gfree(xs_parent.xs);
		return (true);
	}
	gfree(xs_parent.xs);
	return (false);
}
