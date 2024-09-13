#include "../betterft.h"

bool	ft_equalsf(float a, float b)
{
	const float	EPSILON = 0.00001f;
	float		diff;

	diff = a - b;
	if (diff < 0)
		diff = -diff;
	return (diff < EPSILON);
}

bool	ft_equalsd(double a, double b)
{
	const double	EPSILON = 0.0000000001;
	double			diff;

	diff = a - b;
	if (diff < 0)
		diff = -diff;
	return (diff < EPSILON);
}
