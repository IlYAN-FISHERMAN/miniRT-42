#include "plane.h"
#include "../exit_handler/exit_handler.h"

//  intersect_plane: Check if ray intersects plane
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the plane, false otherwise
static t_xs_parent	intersect_plane(t_object *object, t_ray ray)
{
	t_xs_parent	xs_parent;

	ray = transform(ray, object->inv_transform);
	xs_parent = xs();
	if (ft_equalsd(ray.direction.y, 0))
		return (xs_parent);
	add_intersection(&xs_parent,
		intersection(-ray.origin.y / ray.direction.y, object));
	return (xs_parent);
}

//  uv_mapping_plane: Map a point on the plane to a uv coordinate
//  @param object_p The point on the plane
//  @return The uv coordinate
static t_vector2	uv_mapping_plane(t_point3 object_p)
{
	return (vector2(object_p.x - floor(object_p.x),
			object_p.z - floor(object_p.z)));
}

//  normal_at_plane: Get the normal at a point on the plane
//  @param object The object
//  @param world_point The point on the plane
//  @return The normal at the point
static t_vector3	normal_at_plane(t_object *object, t_point3 world_point)
{
	t_point3	object_p;
	t_vector3	object_n;
	t_vector3	world_n;

	object_p = tm4mul(object->inv_transform, world_point);
	object_n = vector3(0, 1, 0);
	if (object->mat.bumpmap)
		object_n = perturbn(object_n,
				get_bumpv(object->mat.bumpmap, uv_mapping_plane(object_p)));
	world_n = tm4mul(object->tinv_transform, object_n);
	world_n.w = VECTOR;
	vnormalize(&world_n);
	return (world_n);
}

t_object	*new_plane(t_point3 origin, t_vector3 normal, t_color color)
{
	t_object	*object;

	origin.w = POINT;
	normal.w = VECTOR;
	vnormalize(&normal);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_plane));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	*((t_plane *)object->data) = (t_plane){.origin = origin,
		.normal = normal, .color = color};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.transform = m4translation(origin), .intersect = intersect_plane,
		.type = o_plane, .normal_at = normal_at_plane};
	object->transform = m4mul(object->transform,
			m4rotating_dir(point3(0, 1, 0), ((t_plane *)object->data)->normal));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
