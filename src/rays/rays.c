#include "rays.h"

t_point3	ray_at(t_ray ray, float t)
{
	return ((t_point3)vadd((t_vector3)ray.origin, vmul(ray.direction, t)));
}

t_ray	ray(t_point3 origin, t_vector3 direction, float t_max)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.t_max = t_max;
	return (ray);
}
