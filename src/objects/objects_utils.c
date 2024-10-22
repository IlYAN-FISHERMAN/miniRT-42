#include "objects.h"

bool	quadratic_intersection(t_quadratic *quad)
{
	double		discriminant;

	discriminant = quad->b * quad->b - 4 * quad->a * quad->c;
	if (discriminant < 0)
	{
		quad->t[0] = 0;
		quad->t[1] = 0;
		return (false);
	}
	quad->t[0] = (-quad->b - sqrt(discriminant)) / (2 * quad->a);
	quad->t[1] = (-quad->b + sqrt(discriminant)) / (2 * quad->a);
	return (true);
}
