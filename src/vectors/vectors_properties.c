#include "vectors.h"

float	vlength(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vector	vnormalized(t_vector v)
{
	return (vdiv(v, vlength(v)));
}

t_vector	*vnormalize(t_vector *v)
{
	t_vector	norm;

	norm = vnormalized(*v);
	v->x = norm.x;
	v->y = norm.y;
	v->z = norm.z;
	return (v);
}
