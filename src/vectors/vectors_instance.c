#include "vectors.h"

t_vector3	vector3(double x, double y, double z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_point3	point3(double x, double y, double z)
{
	return (vector3(x, y, z));
}

t_vector2	vector2(double u, double v)
{
	t_vector2	vector;

	vector.u = u;
	vector.v = v;
	return (vector);
}
