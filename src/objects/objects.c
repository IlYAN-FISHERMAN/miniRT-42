#include "objects.h"

t_mat	material(t_color color, float diff,
	float spec, float shininess)
{
	return ((t_mat){
		.color = color,
		.diff = diff,
		.spec = spec,
		.shin = shininess
	});
}

t_mat	dfmaterial(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.9,
		.spec = 0.9,
		.shin = 200
	});
}

bool	intersect(t_intersect *intersect, t_scene *objects)
{
	(void)intersect;
	(void)objects;
	return (true);
}

void	set_transform(t_object *obj, t_matrix4 transform)
{
	obj->transform = m4mul(transform, obj->transform);
}
