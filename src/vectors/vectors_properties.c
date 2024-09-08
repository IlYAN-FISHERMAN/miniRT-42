#include "vectors.h"

double	vlength2(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vlength(t_vector3 v)
{
	return (sqrt(vlength2(v)));
}

t_vector3	vnormalized(t_vector3 v)
{
	return (vdiv(v, vlength(v)));
}

t_vector3	*vnormalize(t_vector3 *v)
{
	t_vector3	norm;

	norm = vnormalized(*v);
	v->x = norm.x;
	v->y = norm.y;
	v->z = norm.z;
	return (v);
}
