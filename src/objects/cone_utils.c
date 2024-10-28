#include "cone.h"

t_vector2	uv_mapping_cone(t_point3 local_point, bool is_caps)
{
	double	theta;
	double	u;
	double	v;

	if (!is_caps)
	{
		theta = atan2(local_point.x, local_point.z);
		u = (theta + M_PI) / (2 * M_PI);
		v = local_point.y;
	}
	else
	{
		u = (local_point.x + 1) * 0.5;
		v = (local_point.z + 1) * 0.5;
	}
	return (vector2(u, v));
}
