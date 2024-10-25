#include "objects.h"

t_vector3	normal_at(t_object *obj, t_point3 world_point)
{
	t_point3	local_point;
	t_vector3	local_normal;
	t_vector3	world_normal;

	local_point = tm4mul(obj->inv_transform, world_point);
	local_normal = obj->local_normal_at(obj, local_point);
	world_normal = tm4mul(obj->tinv_transform, local_normal);
	world_normal.w = 0;
	vnormalize(&world_normal);
	return (world_normal);
}

t_xs_parent	intersect_at(t_object *obj, t_ray ray)
{
	return (obj->local_intersect(obj, transform(ray, obj->inv_transform)));
}

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
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}

t_mat	dfmaterial(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.9,
		.spec = 0.9,
		.shin = 200,
		.reflect = 0.1,
		.transp = 0.0,
		.refract_idx = 1.0,
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}

void	set_transform(t_object *obj, t_matrix4 transform)
{
	obj->transform = m4mul(obj->transform, transform);
}
