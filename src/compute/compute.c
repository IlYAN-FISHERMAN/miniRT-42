#include "compute.h"
#include "../miniRT.h"

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
	comps.reflectv = vreflect(r.direction, comps.normalv);
	return (comps);
}

t_color	shade_hit(t_comps comps, bool fast, int remaining)
{
	t_lightning	ln;
	t_color		c;
	bool		in_shadow;
	t_minirt	*minirt;

	minirt = get_minirt();
	c = color(0, 0, 0);
	ln = new_lightning(0, comps.point,
			comps.eyev, comps.normalv);
	ln.amb = minirt->amb;
	ln.l = get_next_light(minirt->scene);
	while (ln.l)
	{
		in_shadow = (!fast && is_shadowed(minirt->scene, comps.point, ln.l));
		c = color_add(c, lightning(comps.object, ln, in_shadow));
		ln.l = get_next_light(minirt->scene);
	}
	return (color_add(c,
			reflected_color(comps, fast, remaining)));
}

t_color	color_at(t_ray r, bool fast, int remaining)
{
	t_xs_parent	xs_parent;
	t_intersect	*i;
	t_comps		comps;
	t_minirt	*minirt;

	minirt = get_minirt();
	xs_parent = intersect_world(minirt->scene, r);
	i = hit(xs_parent);
	if (!i)
		return (color(0, 0, 0));
	comps = precompute(i, r);
	gfree(xs_parent.xs);
	return (shade_hit(comps, fast, remaining));
}

t_color	reflected_color(t_comps comps, bool fast, int remaining)
{
	t_ray		r;

	if (remaining <= 0 || fast || comps.object->mat.reflect == 0)
		return (color(0, 0, 0));
	r = ray(comps.over_point, comps.reflectv);
	return (color_scalar(color_at(r, false, remaining - 1),
			comps.object->mat.reflect));
}
