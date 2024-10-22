#include "compute.h"

t_color	reflected_color(t_comps *comps, bool fast, int remaining)
{
	t_ray		r;

	(void)fast;
	if (remaining <= 0 || comps->object->mat.reflect == 0)
		return (color(0, 0, 0));
	r = ray(comps->over_point, comps->reflectv);
	return (color_scalar(color_at(r, fast, remaining - 1),
			comps->object->mat.reflect));
}

t_color	refracted_color(t_comps *comps, bool fast, int remaining)
{
	t_vector3	dir;

	if (fast || comps->object->mat.transp == 0 || remaining <= 0)
		return (color(0, 0, 0));
	comps->n_ratio = comps->n1 / comps->n2;
	comps->cos_i = vdot(comps->eyev, comps->normalv);
	comps->sin2_t = comps->n_ratio * comps->n_ratio
		* (1.0f - comps->cos_i * comps->cos_i);
	if (comps->sin2_t > 1.0)
		return (color(0, 0, 0));
	comps->cos_t = sqrt(1.0 - comps->sin2_t);
	dir = vsub(vmul(comps->normalv, (comps->n_ratio * comps->cos_i
					- comps->cos_t)), vmul(comps->eyev, comps->n_ratio));
	return (color_scalar(color_at(ray(comps->under_point, dir),
				fast, remaining - 1), comps->object->mat.transp));
}

double	schlick(t_comps *comps)
{
	double		cos;
	double		r0;
	double		sin2_t;
	double		n_ratio;

	cos = comps->cos_i;
	if (!cos)
		cos = vdot(comps->eyev, comps->normalv);
	if (comps->n1 > comps->n2)
	{
		n_ratio = comps->n_ratio;
		if (!n_ratio)
			n_ratio = comps->n1 / comps->n2;
		sin2_t = comps->sin2_t;
		if (!sin2_t)
			sin2_t = n_ratio * n_ratio * (1.0f - cos * cos);
		if (sin2_t > 1.0)
			return (1.0);
		cos = comps->cos_t;
		if (!cos)
			cos = sqrt(1.0 - sin2_t);
	}
	r0 = (comps->n1 - comps->n2) / (comps->n1 + comps->n2);
	r0 *= r0;
	return (r0 + (1 - r0) * pow(1 - cos, 5));
}
