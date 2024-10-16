#include "objects.h"

bool	quadratic_intersection(double a, double b,
	double c, t_object *obj)
{
	double		discriminant;
	double		tmp;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		obj->t[0] = 0;
		obj->t[1] = 0;
		return (false);
	}
	obj->t[0] = (-b - sqrt(discriminant)) / (2 * a);
	obj->t[1] = (-b + sqrt(discriminant)) / (2 * a);
	if (obj->t[0] > obj->t[1])
	{
		tmp = obj->t[0];
		obj->t[0] = obj->t[1];
		obj->t[1] = tmp;
	}
	return (true);
}
