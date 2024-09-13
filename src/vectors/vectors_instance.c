#include "vectors.h"

t_tuple4	tuple4(double x, double y, double z, double w)
{
	return ((t_tuple4){.x = x, .y = y, .z = z, .w = w});
}

t_vector3	vector3(double x, double y, double z)
{
	return (tuple4(x, y, z, VECTOR));
}

t_point3	point3(double x, double y, double z)
{
	return (tuple4(x, y, z, POINT));
}

t_vector2	vector2(double u, double v)
{
	return (tuple4(u, v, 0, VECTOR));
}

t_point2	point2(double u, double v)
{
	return (tuple4(u, v, 0, POINT));
}
