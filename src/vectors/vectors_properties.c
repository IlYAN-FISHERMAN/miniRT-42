#include "vectors.h"

float	vlength2(t_vector3 v)
{
	if (DEBUG && v.w == POINT)
		printf("Warning: Getting the squared length of a point\n");
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_vector3	vnormalized(t_vector3 v)
{
	float	invlen;

	if (DEBUG && v.w == POINT)
		printf("Warning: Normalizing a point\n");
	invlen = ft_invsqrt_iter(vlength2(v), 2);
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
	invlen = ft_invsqrt_iter(vlength2(*v), 2);
	*v = (t_vector3){
		v->x * invlen,
		v->y * invlen,
		v->z * invlen,
		VECTOR
	};
}
