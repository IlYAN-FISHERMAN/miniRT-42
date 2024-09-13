#include "vectors.h"

double	vlength2(t_vector3 v)
{
	if (DEBUG && v.w == POINT)
		printf("Warning: Getting the squared length of a point\n");
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vlength(t_vector3 v)
{
	if (DEBUG && v.w == POINT)
		printf("Warning: Getting the length of a point\n");
	return (sqrt(vlength2(v)));
}

t_vector3	vnormalized(t_vector3 v)
{
	if (DEBUG && v.w == POINT)
		printf("Warning: Normalizing a point\n");
	return (vdiv(v, vlength(v)));
}

t_vector3	*vnormalize(t_vector3 *v)
{
	if (DEBUG && v->w == POINT)
		printf("Warning: Normalizing a point\n");
	*v = vdiv(*v, vlength(*v));
}
