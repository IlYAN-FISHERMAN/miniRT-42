#include "matrix.h"

t_matrix4	m4default(void)
{
	return ((t_matrix4){.data = {
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1},
		}});
}

t_matrix4	m4translation(t_tuple4 t)
{
	return ((t_matrix4){.data = {
			{1, 0, 0, t.x},
			{0, 1, 0, t.y},
			{0, 0, 1, t.z},
			{0, 0, 0, 1}
		}});
}

t_matrix4	m4scaling(t_tuple4 t)
{
	return ((t_matrix4){.data = {
			{t.x, 0, 0, 0},
			{0, t.y, 0, 0},
			{0, 0, t.z, 0},
			{0, 0, 0, 1}
		}});
}

t_matrix4	m4rotating(double radian, t_axis axis)
{
	double	cosr;
	double	sinr;

	cosr = cosf(radian);
	sinr = sinf(radian);
	if (axis == X_AXIS)
		return ((t_matrix4){.data = {
				{1, 0, 0, 0},
				{0, cosr, -sinr, 0},
				{0, sinr, cosr, 0},
				{0, 0, 0, 1}}});
	else if (axis == Y_AXIS)
		return ((t_matrix4){.data = {
				{cosr, 0, sinr, 0},
				{0, 1, 0, 0},
				{-sinr, 0, cosr, 0},
				{0, 0, 0, 1}}});
	else
		return ((t_matrix4){.data = {
				{cosr, -sinr, 0, 0},
				{sinr, cosr, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}}});
}

t_matrix4	m4shearing(t_shearing sh)
{
	return ((t_matrix4){.data = {
			{1, sh.xy, sh.xz, 0},
			{sh.yx, 1, sh.yz, 0},
			{sh.zx, sh.zy, 1, 0},
			{0, 0, 0, 1}
		}});
}
