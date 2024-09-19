#include "vectors.h"

t_tuple4	tuple4(float x, float y, float z, float w)
{
	return ((t_tuple4){.x = x, .y = y, .z = z, .w = w});
}

t_vector3	vector3(float x, float y, float z)
{
	return (tuple4(x, y, z, VECTOR));
}

t_point3	point3(float x, float y, float z)
{
	return (tuple4(x, y, z, POINT));
}

t_vector2	vector2(float u, float v)
{
	return (tuple4(u, v, 0, VECTOR));
}

t_point2	point2(float u, float v)
{
	return (tuple4(u, v, 0, POINT));
}
