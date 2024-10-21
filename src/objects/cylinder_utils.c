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
	t_xs_parent *xs_parent)
{
	double		y[2];

	y[0] = ray.origin.y + obj->t[0] * ray.direction.y;
	if (y[0] < 1 && y[0] > 0)
		add_intersection(xs_parent, intersection(obj->t[0], obj));
	y[1] = ray.origin.y + obj->t[1] * ray.direction.y;
	if (y[1] < 1 && y[1] > 0)
		add_intersection(xs_parent, intersection(obj->t[1], obj));
}
