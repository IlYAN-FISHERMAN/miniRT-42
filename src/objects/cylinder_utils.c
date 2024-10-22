#include "cylinder.h"

bool	check_cap(t_ray ray, double t)
{
	double		x;
	double		z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (x * x + z * z < 1 || ft_equalsd(x * x + z * z, 1));
}

void	check_bounds(t_object *obj, t_ray ray,
	t_xs_parent *xs_parent, t_quadratic *quad)
{
	double		y[2];

	y[0] = ray.origin.y + quad->t[0] * ray.direction.y;
	if (y[0] < 1 && y[0] > 0)
		add_intersection(xs_parent, intersection(quad->t[0], obj));
	y[1] = ray.origin.y + quad->t[1] * ray.direction.y;
	if (y[1] < 1 && y[1] > 0)
		add_intersection(xs_parent, intersection(quad->t[1], obj));
}
