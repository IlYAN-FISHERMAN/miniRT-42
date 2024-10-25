#include "lightning.h"

static inline t_color	diffuse(t_object *obj,
	t_color eff_color, double l_dot_n)
{
	if (l_dot_n < 0)
		return (color(0, 0, 0));
	return (color_scalar(eff_color, obj->mat.diff * l_dot_n));
}

static inline t_color	specular(t_object *obj, t_lightning ln,
	t_vector3 lv, double ldn)
{
	double		rde;
	t_vector3	reflectv;

	if (ldn < 0)
		return (color(0, 0, 0));
	reflectv = vreflect(vneg(lv), ln.nv);
	rde = vdot(reflectv, ln.ev);
	if (rde < 0 || ft_equalsd(rde, 0))
		return (color(0, 0, 0));
	return (color_scalar(((t_light *)(ln.l->data))->c_rgb,
		obj->mat.spec * pow(rde, obj->mat.shin)));
}

t_lightning	new_lightning(t_object *l, t_point3 p, t_vector3 ev, t_vector3 nv)
{
	return ((t_lightning){.l = l, .p = p, .ev = ev, .nv = nv});
}

t_color	lightning(t_object *obj, t_lightning ln, bool in_shadow, bool fast)
{
	t_color		eff_color;
	t_vector3	lightv;
	double		l_dot_n;
	t_color		c[3];

	(void)fast;
	if (obj->mat.pattern.has_pattern)
		obj->mat.color = obj->mat.pattern
			.pattern_at_object(obj->mat.pattern, obj, ln.p);
	eff_color = color_mult(obj->mat.color, ((t_light *)(ln.l->data))->c_rgb);
	c[0] = color_mult(ln.amb->c_rgb, eff_color);
	if (in_shadow)
		return (c[0]);
	lightv = vnormalized(vsub(((t_light *)(ln.l->data))->pos, ln.p));
	l_dot_n = vdot(lightv, ln.nv);
	c[1] = diffuse(obj, eff_color, l_dot_n);
	c[2] = specular(obj, ln, lightv, l_dot_n);
	return (color_add(c[0], color_add(c[1], c[2])));
}
