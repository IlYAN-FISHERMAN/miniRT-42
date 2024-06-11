#include "vectors.h"

t_vector	vadd(t_vector v, t_vector u)
{
	return ((t_vector){v.x + u.x, v.y + u.y, v.z + u.z});
}

t_vector	vsub(t_vector v, t_vector u)
{
	return ((t_vector){v.x - u.x, v.y - u.y, v.z - u.z});
}

t_vector	vmul(t_vector v, float scalar)
{
	return ((t_vector){v.x * scalar, v.y * scalar, v.z * scalar});
}

t_vector	vdiv(t_vector v, float scalar)
{
	return ((t_vector){v.x / scalar, v.y / scalar, v.z / scalar});
}
