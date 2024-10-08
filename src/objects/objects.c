#include "objects.h"

t_material	material(float ambient, float diffuse,
	float specular, float shininess)
{
	return ((t_material){
		.color = color(0, 255, 0),
		.ambient = ambient,
		.diffuse = diffuse,
		.specular = specular,
		.shininess = shininess
	});
}

bool	does_intersect(t_ray ray, t_scene *objects)
{
	// redo
	(void)ray;
	(void)objects;
	return (true);
}

bool	intersect(t_intersect *intersect, t_scene *objects)
{
	// redo
	(void)intersect;
	(void)objects;
	return (true);
}

void	set_transform(t_object *obj, t_matrix4 transform)
{
	obj->transform = transform;
}
