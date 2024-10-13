#include "compute.h"

t_comps	precompute(t_intersect *i, t_ray r)
{
	t_comps	comps;

	comps.t = i->t;
	comps.object = i->object;
	comps.point = ray_at(r, comps.t);
	comps.eyev = vneg(r.direction);
	comps.normalv = comps.object->normal_at(i->object, comps.point);
	if (vdot(comps.normalv, comps.eyev) < 0 && !ft_equalsd(comps.t, 0))
	{
		comps.inside = true;
		comps.normalv = vneg(comps.normalv);
	}
	else
		comps.inside = false;
	comps.over_point = vadd(comps.point, vmul(comps.normalv, EPSILONF));
	return (comps);
}

t_color	shade_hit(t_scene *scene, t_amb *amb, t_comps comps)
{
	t_lightning	ln;
	t_color		c;
	bool		in_shadow;

	c = color(0, 0, 0);
	ln = new_lightning(0, comps.point,
			comps.eyev, comps.normalv);
	ln.l = get_next_light(scene);
	while (ln.l)
	{
		in_shadow = is_shadowed(scene, comps.point, ln.l);
		c = color_add(c, lightning(comps.object, amb, ln, in_shadow));
		ln.l = get_next_light(scene);
	}
	return (c);
}

t_color	color_at(t_scene *scene, t_amb *amb, t_ray r)
{
	t_xs_parent	xs_parent;
	t_intersect	*i;
	t_comps		comps;

	xs_parent = intersect_world(scene, r);
	i = hit(xs_parent);
	if (!i)
		return (color(0, 0, 0));
	comps = precompute(i, r);
	gfree(xs_parent.xs);
	return (shade_hit(scene, amb, comps));
}
