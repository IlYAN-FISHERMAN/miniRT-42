#include "vectors.h"

float	vlength2(t_vector3 v)
{
	if (DEBUG && v.w == POINT)
		printf("Warning: Getting the squared length of a point\n");
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

t_vector3	vnormalized(t_vector3 v)
{
	float	invlen;

	if (DEBUG && v.w == POINT)
		printf("Warning: Normalizing a point\n");
	invlen = 1 / sqrtf(vlength2(v));
	return ((t_vector3){
		v.x * invlen,
		v.y * invlen,
		v.z * invlen,
		VECTOR
	});
}

t_vector3	*vnormalize(t_vector3 *v)
{
	float	invlen;

	if (DEBUG && v->w == POINT)
		printf("Warning: Normalizing a point\n");
	invlen = 1 / sqrtf(vlength2(*v));
	v->x *= invlen;
	v->y *= invlen;
	v->z *= invlen;
	return (v);
}
