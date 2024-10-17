#include "matrix.h"

t_matrix4	m4rodrig_rot(t_vector3 a, double angle)
{
	double		cost;
	double		sint;
	double		xt;
	double		yt;
	double		zt;

	cost = cos(angle);
	sint = sin(angle);
	a = vnormalized(a);
	xt = a.x * (1 - cost);
	yt = a.y * (1 - cost);
	zt = a.z * (1 - cost);
	return ((t_matrix4){.data = {
			{cost + a.x * xt, a.x * yt - a.z * sint, a.x * zt + a.y * sint, 0},
			{a.y * xt + a.z * sint, cost + a.y * yt, a.y * zt - a.x * sint, 0},
			{a.z * xt - a.y * sint, a.z * yt + a.x * sint, cost + a.z * zt, 0},
			{0, 0, 0, 1}
		}
	});
}

t_matrix4	m4rotating_dir(t_vector3 from, t_vector3 to)
{
	t_vector3	axis;
	double		angle;

	if (from.x == to.x && from.y == to.y && from.z == to.z)
		return (m4default());
	else if (from.x == -to.x && from.y == -to.y && from.z == -to.z)
		return (m4scaling(vector3(-1, -1, -1)));
	axis = vcross(from, to);
	vnormalize(&axis);
	angle = acos(vdot(from, to));
	return (m4rodrig_rot(axis, angle));
}
