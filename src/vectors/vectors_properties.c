#include "vectors.h"

float	vlength2(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

float	vlength(t_vector v)
{
	return (sqrt(vlength2(v)));
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
