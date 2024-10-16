#include "objects.h"

t_xs_parent	quadratic_intersection(double a, double b,
	double c, t_object *obj)
{
	t_xs_parent	inters;
	double		discriminant;
	double		t1;
	double		t2;

	inters = xs();
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (inters);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	add_intersection(&inters, intersection(t1, obj));
	add_intersection(&inters, intersection(t2, obj));
	return (inters);
}
