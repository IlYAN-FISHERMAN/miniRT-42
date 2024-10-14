#include "compute.h"

t_color	reflected_color(t_comps *comps, bool fast, int remaining)
{
	t_ray		r;

	if (remaining <= 0 || fast || comps->object->mat.reflect == 0)
		return (color(0, 0, 0));
	r = ray(comps->over_point, comps->reflectv);
	return (color_scalar(color_at(r, false, remaining - 1),
			comps->object->mat.reflect));
}

t_color	refracted_color(t_comps *comps, bool fast, int remaining)
{
	t_vector3	dir;

	if (fast || comps->object->mat.transp == 0 || remaining <= 0)
		return (color(0, 0, 0));
	if (comps->sin2_t > 1)
		return (color(0, 0, 0));
	dir = vsub(vmul(comps->normalv,
				(comps->n_ratio * comps->cos_i - comps->cos_t)),
			vmul(comps->eyev, comps->n_ratio));
	return (color_scalar(color_at(ray(comps->under_point, dir),
				false, remaining - 1), comps->object->mat.transp));
}

double	schlick(t_comps *comps)
{
	double		cos;
	double		r0;

	cos = comps->cos_i;
	if (comps->n1 > comps->n2)
	{
		if (comps->sin2_t > 1.0)
			return (1.0);
		cos = comps->cos_t;
	}
	r0 = (comps->n1 - comps->n2) / (comps->n1 + comps->n2);
	r0 *= r0;
	return (r0 + (1 - r0) * pow(1 - cos, 5));
}
