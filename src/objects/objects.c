#include "objects.h"
#include "../camera/camera.h"

t_mat	material(t_color color, double diff,
	double spec, double shininess)
{
	return ((t_mat){
		.color = color,
		.diff = diff,
		.spec = spec,
		.shin = shininess,
		.reflect = 0.5,
		.transp = 0.5,
		.refract_idx = 1.5,
		.pattern = pattern()
	});
}

t_mat	dfmaterial(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.9,
		.spec = 0.9,
		.shin = 200,
		.reflect = 0.5,
		.transp = 0.5,
		.refract_idx = 1.5,
		.pattern = pattern()
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

void	transform_camera(t_camera *camera, t_matrix4 transform)
{
	camera->transform = m4mul(transform, camera->transform);
}
