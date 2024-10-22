#include "bumpmap.h"

t_bumpmap	*dfbumpmap(void)
{
	return (0);
}

double	get_bumpv(t_bumpmap *bumpmap, t_vector2 uv)
{
	int		x;
	int		y;

	x = (int)(uv.x * (bumpmap->width - 1));
	y = (int)(uv.y * (bumpmap->height - 1));
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if ((size_t)x >= bumpmap->width)
		x = bumpmap->width - 1;
	if ((size_t)y >= bumpmap->height)
		y = bumpmap->height - 1;
	return ((double)bumpmap->data[y * bumpmap->width + x] / 255.0);
}

t_vector3	perturbn(t_vector3 normal, double bump_value)
{
	t_vector3	up;
	t_vector3	tangent;
	t_vector3	bitan;
	t_vector3	perturb_normal;

	if (fabs(normal.y) > 0.9)
		up = vector3(1, 0, 0);
	else
		up = vector3(0, 1, 0);
	tangent = vnormalized(vcross(up, normal));
	bitan = vnormalized(vcross(normal, tangent));
	perturb_normal = vadd(normal, vmul(tangent, bump_value * BUMP_SCALE));
	perturb_normal = vadd(perturb_normal, vmul(bitan, bump_value * BUMP_SCALE));
	vnormalize(&perturb_normal);
	return (perturb_normal);
}
