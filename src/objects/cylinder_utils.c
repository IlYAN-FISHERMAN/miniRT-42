#include "cylinder.h"

bool	check_cap(t_ray ray, double t)
{
	double		x;
	double		z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z < 1 || ft_equalsd(x * x + z * z, 1));
}
