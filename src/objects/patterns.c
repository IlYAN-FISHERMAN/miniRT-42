#include "patterns.h"
#include "objects.h"

static t_color	stripe_at_object(t_pattern pattern,
					void *object, t_point3 point)
{
	t_point3	obj_point;
	t_point3	pattern_point;

	obj_point = tm4mul(((t_object *)object)->inv_transform, point);
	pattern_point = tm4mul(pattern.transform, obj_point);
	if ((int)floor(pattern_point.x) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}

t_pattern	pattern(void)
{
	return ((t_pattern){.a = color(0, 0, 0), .b = color(0, 0, 0),
		.pattern_at_object = 0, .has_pattern = false,
		.transform = m4default()});
}

t_pattern	stripe_pattern(t_color a, t_color b)
{
	return ((t_pattern){.a = a, .b = b, .pattern_at_object = stripe_at_object,
		.has_pattern = true, .transform = m4default()});
}

static t_color
	checkboard_at_object(t_pattern pattern, void *object, t_point3 point)
{
	t_point3	obj_point;
	t_point3	pattern_point;

	obj_point = tm4mul(((t_object *)object)->inv_transform, point);
	pattern_point = tm4mul(pattern.transform, obj_point);
	if (((int)floor(pattern_point.x) + (int)floor(pattern_point.z)) % 2 == 0)
		return (pattern.a);
	return (pattern.b);
}

t_pattern	checkboard_pattern(t_color a, t_color b)
{
	return ((t_pattern){.a = a, .b = b,
		.pattern_at_object = checkboard_at_object,
		.has_pattern = true, .transform = m4default()});
}
