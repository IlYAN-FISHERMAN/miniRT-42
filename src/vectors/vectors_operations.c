#include "vectors.h"

t_vector3	vadd(t_vector3 v, t_vector3 u)
{
	if (DEBUG && u.w == POINT && v.w == POINT)
		printf("Warning: Adding two points\n");
	return ((t_vector3){v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w});
}

t_vector3	vsub(t_vector3 v, t_vector3 u)
{
	if (DEBUG && u.w == VECTOR && v.w == POINT)
		printf("Warning: Subtracting a point from a vector\n");
	return ((t_vector3){v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w});
}

t_vector3	vmul(t_vector3 v, double scalar)
{
	return ((t_vector3){v.x * scalar, v.y * scalar, v.z * scalar, v.w});
}

t_vector3	vneg(t_vector3 v)
{
	return ((t_vector3){-v.x, -v.y, -v.z, v.w});
}

t_vector3	vdiv(t_vector3 v, double scalar)
{
	return ((t_vector3){v.x / scalar, v.y / scalar, v.z / scalar, v.w});
}
