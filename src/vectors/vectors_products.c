#include "vectors.h"

float	vdot(t_vector v, t_vector u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

t_vector	vcross(t_vector v, t_vector u)
{
	return ((t_vector){
		v.y * u.z - v.z * u.y,
		v.z * u.x - v.x * u.z,
		v.x * u.y - v.y * u.x
	});
}
