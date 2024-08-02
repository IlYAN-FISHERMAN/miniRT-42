#include "light.h"

t_object	*new_light(t_point3 origin, t_color color, float brightness)
{
	t_light		*light;
	t_object	*object;

	light = galloc(sizeof(t_light));
	if (!light)
		return (0);
	light->origin = origin;
	light->color = color;
	light->brightness = brightness;
	object = ft_calloc(1, sizeof(t_object));
	if (!object)
	{
		gfree(light);
		return (0);
	}
	object->type = o_light;
	object->data = light;
	return (object);
}
