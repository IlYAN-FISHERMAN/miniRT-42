#include "color.h"

t_color	color_add(t_color c, t_color d)
{
	return (color(byte_clamp((int)c.r + (int)d.r),
			byte_clamp((int)c.g + (int)d.g),
			byte_clamp((int)c.b + (int)d.b)));
}

t_color	color_mult(t_color c, t_color d)
{
	return (color(byte_clamp((int)c.r * (int)d.r >> 8),
			byte_clamp((int)c.g * (int)d.g >> 8),
			byte_clamp((int)c.b * (int)d.b >> 8)));
}

t_color	color_scalar(t_color c, double scalar)
{
	return (color(byte_clamp((int)c.r * scalar),
			byte_clamp((int)c.g * scalar),
			byte_clamp((int)c.b * scalar)));
}

t_color	apply_gamma(t_color c, double gamma, double exposure)
{
	return (color(byte_clamp(pow((int)c.r * exposure, gamma)),
			byte_clamp(pow((int)c.g * exposure, gamma)),
			byte_clamp(pow((int)c.b * exposure, gamma))));
}
