#include "vectors.h"

double	vdot(t_vector3 v, t_vector3 u)
{
	if (DEBUG && (v.w == POINT || u.w == POINT))
		printf("Warning: Getting the dot product of a point\n");
	return (v.x * u.x + v.y * u.y + v.z * u.z + v.w * u.w);
}

t_vector3	vcross(t_vector3 v, t_vector3 u)
{
	if (DEBUG && (v.w == POINT || u.w == POINT))
		printf("Warning: Getting the cross product of a point\n");
	return (vector3(
			v.y * u.z - v.z * u.y,
			v.z * u.x - v.x * u.z,
			v.x * u.y - v.y * u.x
		)
	);
}
