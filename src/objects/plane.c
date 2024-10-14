#include "plane.h"
#include "../exit_handler/exit_handler.h"

//  intersect_plane: Check if ray intersects plane
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the plane, false otherwise
static t_xs_parent	intersect_plane(t_object *object, t_ray ray)
{
	t_xs_parent	xs_parent;
	float		t;
	t_vector3	normal;

	ray = transform(ray, object->inv_transform);
	normal = ((t_plane *)object->data)->normal;
	xs_parent = xs();
	if (fabs(vdot(ray.direction, normal)) < EPSILONF)
		return (xs_parent);
	t = -vdot(ray.origin, normal) / vdot(ray.direction, normal);
	xs_parent.xs = galloc(sizeof(t_intersect));
	if (!xs_parent.xs)
		crash_exit(get_minirt(),
			(char *[]){"miniRT", "render", 0}, "Malloc failed");
	xs_parent.xs[0] = intersection(t, object);
	xs_parent.count = 1;
	return (xs_parent);
}

//  normal_at_plane: Get the normal at a point on the plane
//  @param object The object
//  @param world_point The point on the plane
//  @return The normal at the point
static t_vector3	normal_at_plane(t_object *object, t_point3 world_point)
{
	(void)world_point;
	return (tm4mul(object->transform, ((t_plane *)object->data)->normal));
}


t_object	*new_plane(t_point3 origin, t_vector3 normal, t_color color)
{
	t_object	*object;

	origin.w = POINT;
	normal.w = VECTOR;
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
		.transform = m4default(), .intersect = intersect_plane,
		.type = o_plane, .normal_at = normal_at_plane};
	object->transform = m4translation(vector3(origin.x, origin.y, origin.z));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
