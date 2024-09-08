#include "vectors.h"

double	vdot(t_vector3 v, t_vector3 u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

t_vector3	vcross(t_vector3 v, t_vector3 u)
{
	return ((t_vector3){
		v.y * u.z - v.z * u.y,
		v.z * u.x - v.x * u.z,
		v.x * u.y - v.y * u.x
	});
}
