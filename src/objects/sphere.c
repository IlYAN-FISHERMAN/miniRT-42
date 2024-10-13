#include "sphere.h"

//	find_intersection: Find the intersection of a ray with a sphere
//	and return the intersection data
//	@param a The a value of the quadratic equation
//	@param b The b value of the quadratic equation
//	@param c The c value of the quadratic equation
//	@param obj The object to check
static t_xs_parent	find_intersection(float a, float b, float c, t_object *obj)
{
	t_xs_parent	inters;
	float	discriminant;
	float	t1;
	float	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0f)
		return ((t_xs_parent){0});
	discriminant = sqrtf(discriminant);
	t1 = (-b - discriminant) / (2 * a);
	t2 = (-b + discriminant) / (2 * a);
	inters = xs();
	add_intersection(&inters, intersection(t1, obj));
	add_intersection(&inters, intersection(t2, obj));
	return (inters);
}

//  intersect_sphere: Check if ray intersects sphere and update
//  intersection data
//  @param intersect The intersection data
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the sphere, false otherwise
static t_xs_parent	intersect_sphere(t_object *object, t_ray ray)
{
	t_xs_parent		inters;
	float		a;
	float		b;
	float		c;
	t_point3	sphere_to_ray;

	ray = transform(ray, object->inv_transform);
	ft_bzero(&inters, sizeof(t_xs_parent));
	sphere_to_ray = vsub(ray.origin, ((t_sphere *)object->data)->origin);
	a = vdot(ray.direction, ray.direction);
	b = 2 * (vdot(ray.direction, sphere_to_ray));
	c = vdot(sphere_to_ray, sphere_to_ray) - 1;
	inters = find_intersection(a, b, c, object);
	return (inters);
}

//  normal_at_sphere: Get the normal at a point on the sphere
//  @param object The object
//  @param world_point The point on the sphere
//  @return The normal at the point
static t_vector3	normal_at_sphere(t_object *object, t_point3 world_point)
{
	t_point3	object_p;
	t_point3	object_n;
	t_point3	world_n;

	object_p = tm4mul(object->inv_transform, world_point);
	object_n = vsub(object_p, ((t_sphere *)object->data)->origin);
	world_n = tm4mul(object->tinv_transform, object_n);
	world_n.w = VECTOR;
	vnormalize(&world_n);
	return (world_n);
}

t_object	*new_sphere(t_point3 origin, float radius, t_color color)
{
	t_object	*object;

	origin.w = POINT;
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_sphere));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	*((t_sphere *)object->data) = (t_sphere){.origin = point3(0, 0, 0),
		.radius = 1};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.intersect = intersect_sphere, .type = o_sphere,
		.normal_at = normal_at_sphere};
	object->transform = m4mul(m4translation(origin), m4scaling(vector3(radius, radius, radius)));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
