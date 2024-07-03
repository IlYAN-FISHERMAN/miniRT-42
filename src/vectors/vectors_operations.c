#include "vectors.h"

t_vector3	vadd(t_vector3 v, t_vector3 u)
{
	return ((t_vector3){v.x + u.x, v.y + u.y, v.z + u.z});
}

t_vector3	vsub(t_vector3 v, t_vector3 u)
{
	return ((t_vector3){v.x - u.x, v.y - u.y, v.z - u.z});
}

t_vector3	vmul(t_vector3 v, float scalar)
{
	return ((t_vector3){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vector3	vdiv(t_vector3 v, float scalar)
{
	return ((t_vector3){v.x / scalar, v.y / scalar, v.z / scalar});
}
