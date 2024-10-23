#include "objects.h"

bool	quadratic_intersection(t_quadratic *quad)
{
	double		discriminant;
	double		sqrt_discriminant;

	discriminant = quad->b * quad->b - 4 * quad->a * quad->c;
	if (discriminant < 0)
	{
		quad->t[0] = 0;
		quad->t[1] = 0;
		return (false);
	}
	sqrt_discriminant = sqrt(discriminant);
	quad->t[0] = (-quad->b - sqrt_discriminant) / (2 * quad->a);
	quad->t[1] = (-quad->b + sqrt_discriminant) / (2 * quad->a);
	return (true);
}
