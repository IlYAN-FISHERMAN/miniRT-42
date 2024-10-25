#include "plane.h"
#include "../exit_handler/exit_handler.h"

//  intersect_plane: Check if ray intersects plane
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the plane, false otherwise
static t_xs_parent	intersect_plane(t_object *object, t_ray ray)
{
	t_xs_parent		inters;

	inters = xs();
	if (ft_equalsd(ray.direction.y, 0))
		return (inters);
	add_intersection(&inters,
		intersection(-ray.origin.y / ray.direction.y, object));
	return (inters);
}

//  uv_mapping_plane: Map a point on the plane to a 2D UV coordinate
//  @param local_point The point on the plane
//  @return The UV coordinate
static t_vector2	uv_mapping_plane(t_point3 local_point)
{
	return (vector2(local_point.x - floor(local_point.x),
			local_point.z - floor(local_point.z)));
}

//  normal_at_plane: Get the normal at a point on the plane
//  @param object The object
//  @param local_point The point on the plane
//  @return The normal at the point
static t_vector3	normal_at_plane(t_object *object, t_point3 local_point)
{
	if (object->mat.bumpmap)
		return (perturbn(vector3(0, 1, 0), get_bumpv(object->mat.bumpmap,
					uv_mapping_plane(local_point))));
	return (vector3(0, 1, 0));
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
		.transform = m4translation(origin), .local_intersect = intersect_plane,
		.type = o_plane, .local_normal_at = normal_at_plane};
	object->transform = m4mul(object->transform,
			m4rotating_dir(point3(0, 1, 0), normal));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
