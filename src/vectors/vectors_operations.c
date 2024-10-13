#include "vectors.h"

t_tuple4	vadd(t_tuple4 v, t_tuple4 u)
{
	if (DEBUG && u.w == POINT && v.w == POINT)
		printf("Warning: Adding two points\n");
	return ((t_tuple4){v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w});
}

t_tuple4	vsub(t_tuple4 v, t_tuple4 u)
{
	if (DEBUG && u.w == VECTOR && v.w == POINT)
		printf("Warning: Subtracting a point from a vector\n");
	return ((t_tuple4){v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w});
}

t_tuple4	vneg(t_tuple4 v)
{
	return ((t_tuple4){-v.x, -v.y, -v.z, -v.w});
}

t_tuple4	vmul(t_tuple4 v, double scalar)
{
	return ((t_tuple4){v.x * scalar, v.y * scalar, v.z * scalar, v.w});
}

t_tuple4	vdiv(t_tuple4 v, double scalar)
{
	return ((t_tuple4){v.x / scalar, v.y / scalar, v.z / scalar, v.w});
}
