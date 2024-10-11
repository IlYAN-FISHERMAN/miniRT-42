#include "light.h"

t_object	*new_light(t_point3 pos, t_color rgb, float bright)
{
	t_object	*object;

	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_light));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	((t_light *)object->data)->pos = pos;
	((t_light *)object->data)->rgb = rgb;
	((t_light *)object->data)->bright = bright;
	((t_light *)object->data)->c_rgb = color_scalar(rgb, bright);
	((t_light *)object->data)->is_calc = true;
	object->type = o_light;
	return (object);
}
