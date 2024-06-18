#include "rays.h"

t_point	ray_at(t_ray ray, float t)
{
	return ((t_point)vadd((t_vector)ray.origin, vmul(ray.direction, t)));
}
