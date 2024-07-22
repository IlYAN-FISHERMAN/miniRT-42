#include "vectors.h"

t_vector3	vector3(float x, float y, float z)
{
	t_vector3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_point3	point3(float x, float y, float z)
{
	return (vector3(x, y, z));
}

t_vector2	vector2(float u, float v)
{
	t_vector2	vector;

	vector.u = u;
	vector.v = v;
	return (vector);
}
