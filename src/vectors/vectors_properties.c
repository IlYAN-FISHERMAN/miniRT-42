#include "vectors.h"

double	vlength2(t_vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

t_vector3	vnormalized(t_vector3 v)
{
	double	invlen;

	invlen = 1 / sqrt(vlength2(v));
	return ((t_vector3){
		v.x * invlen,
		v.y * invlen,
		v.z * invlen,
		VECTOR
	});
}

t_vector3	*vnormalize(t_vector3 *v)
{
	double	invlen;

	invlen = 1 / sqrt(vlength2(*v));
	v->x *= invlen;
	v->y *= invlen;
	v->z *= invlen;
	return (v);
}
