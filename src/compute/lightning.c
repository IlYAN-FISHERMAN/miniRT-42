#include "lightning.h"

static t_color	diffuse(t_object *obj, t_color eff_color, float l_dot_n)
{
	if (l_dot_n < 0)
		return (color(0, 0, 0));
	return (color_scalar(eff_color, obj->mat.diff * l_dot_n));
}

static t_color	specular(t_object *obj, t_lightning ln, t_vector3 lv, float ldn)
{
	float		rde;
	t_vector3	reflectv;

	if (ldn < 0)
		return (color(0, 0, 0));
	reflectv = vreflect(vneg(lv), ln.nv);
	rde = vdot(reflectv, ln.ev);
	if (rde < 0 || ft_equalsf(rde, 0))
		return (color(0, 0, 0));
	return (color_scalar(((t_light *)(ln.l->data))->c_rgb,
		obj->mat.spec * powf(rde, obj->mat.shin)));
}

static t_color	ambience(t_amb *amb)
{
	if (!amb->is_calc)
	{
		amb->c_rgb = color_scalar(amb->rgb, amb->light);
		amb->is_calc = true;
	}
	return (amb->c_rgb);
}

t_lightning	new_lightning(t_object *l, t_point3 p, t_vector3 ev, t_vector3 nv)
{
	return ((t_lightning){.l = l,
		.p = p, .ev = ev, .nv = nv});
}

t_color	lightning(t_object *obj, t_amb *amb, t_lightning ln)
{
	t_color		eff_color;
	t_vector3	lightv;
	float		l_dot_n;
	t_color		ambc;

	eff_color = color_mult(obj->mat.color, ((t_light *)(ln.l->data))->c_rgb);
	lightv = vnormalized(vsub(((t_light *)(ln.l->data))->pos, ln.p));
	ambc = color_mult(ambience(amb), eff_color);
	l_dot_n = vdot(lightv, ln.nv);
	return (color_add(ambc, color_add(diffuse(obj, eff_color, l_dot_n),
				specular(obj, ln, lightv, l_dot_n))));
}
