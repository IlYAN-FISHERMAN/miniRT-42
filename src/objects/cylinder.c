#include "cylinder.h"

//  intersect_cylinder: Check if ray intersects cylinder
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the cylinder, false otherwise
static t_xs_parent	intersect_cylinder(t_object *object, t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_point3	cyl_to_ray;

	ray = transform(ray, object->inv_transform);
	cyl_to_ray = vsub(ray.origin, point3(0, 0, 0));
	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (ft_equalsd(a, 0))
		return (xs());
	b = 2 * cyl_to_ray.x * ray.direction.x + 2 * cyl_to_ray.z * ray.direction.z;
	c = cyl_to_ray.x * cyl_to_ray.x + cyl_to_ray.z * cyl_to_ray.z - 1;
	return (quadratic_intersection(a, b, c, object));
}

//  normal_at_cylinder: Get the normal at a point on the cylinder
//  @param object The object
//  @param world_point The point on the cylinder
//  @return The normal at the point
static t_vector3	normal_at_cylinder(t_object *object, t_point3 world_point)
{
	t_point3	object_point;
	t_vector3	normal;

	object_point = tm4mul(object->inv_transform, world_point);
	normal = vector3(object_point.x, 0, object_point.z);
	normal = tm4mul(object->tinv_transform, normal);
	return (vnormalized(normal));
}

t_object	*new_cylinder(t_point3 origin, double *rad_hei,
				t_vector3 normal, t_color color)
{
	t_object	*object;

	origin.w = POINT;
	normal.w = VECTOR;
	vnormalize(&normal);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_cylin));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	*((t_cylin *)object->data) = (t_cylin){.origin = origin,
		.radius = rad_hei[0], .height = rad_hei[1], .normal = normal};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.transform = m4translation(origin), .intersect = intersect_cylinder,
		.type = o_cylin, .normal_at = normal_at_cylinder};
	set_transform(object, m4scaling(vector3(rad_hei[0], rad_hei[1], rad_hei[0])));
	set_transform(object, m4rotating_dir(point3(0, 1, 0), normal));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
