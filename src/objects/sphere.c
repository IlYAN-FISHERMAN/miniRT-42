#include "sphere.h"

t_object	*new_sphere(t_point3 origin, float radius, t_material material)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = galloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	(*sphere) = (t_sphere){.origin = origin, .radius = radius};
	if (!sphere)
		return (0);
	object = galloc(sizeof(t_object));
	if (!object)
	{
		gfree(sphere);
		return (0);
	}
	(*object) = (t_object){.type = o_sphere, .data = sphere,
		.intersect = intersect_sphere, .does_intersect = does_intersect_sphere,
		.transform = m4default(), .normal_at = normal_at_sphere,
		.material = material
	};
	return (object);
}

//	find_intersection: Find the intersection of a ray with a sphere
//	and return the intersection data
//	@param a The a value of the quadratic equation
//	@param b The b value of the quadratic equation
//	@param c The c value of the quadratic equation
//	@param obj The object to check
static t_xs	find_intersection(float a, float b, float c, t_object *obj)
{
	t_xs	inters;
	float	discriminant;
	float	t1;
	float	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0f)
		return ((t_xs){0});
	t1 = (-b - sqrtf(discriminant)) / (2 * a);
	t2 = (-b + sqrtf(discriminant)) / (2 * a);
	inters = xs();
	add_intersection(&inters, intersection(t1, obj));
	add_intersection(&inters, intersection(t2, obj));
	return (inters);
}

t_xs	intersect_sphere(t_object *object, t_ray ray)
{
	t_xs		inters;
	float		a;
	float		b;
	float		c;
	t_point3	sphere_to_ray;

	ray = transform(ray, m4invert(object->transform, 0));
	ft_bzero(&inters, sizeof(t_xs));
	sphere_to_ray = vsub(ray.origin, ((t_sphere *)object->data)->origin);
	a = vdot(ray.direction, ray.direction);
	b = 2 * (vdot(ray.direction, sphere_to_ray));
	c = vdot(sphere_to_ray, sphere_to_ray) - 1;
	inters = find_intersection(a, b, c, object);
	return (inters);
}

bool	does_intersect_sphere(t_ray ray, t_object *object)
{
	t_sphere	*sphere;
	t_ray		local_ray;
	float		a;
	float		b;
	float		c;

	sphere = (t_sphere *)object->data;
	local_ray = ray;
	local_ray.origin = vsub(ray.origin, sphere->origin);
	a = vlength2(ray.direction);
	b = 2.0f * vdot(local_ray.direction, local_ray.origin);
	c = vlength2(local_ray.origin) - (sphere->radius * sphere->radius);
	if (b * b - 4 * a * c < 0.0f)
		return (false);
	if ((-b - sqrtf(b * b - 4 * a * c)) / (2 * a) > RAY_T_MIN
		&& (-b - sqrtf(b * b - 4 * a * c)) / (2 * a) < RAY_T_MAX)
		return (true);
	if ((-b + sqrtf(b * b - 4 * a * c)) / (2 * a) > RAY_T_MIN
		&& (-b + sqrtf(b * b - 4 * a * c)) / (2 * a) < RAY_T_MAX)
		return (true);
	return (false);
}

t_vector3	normal_at_sphere(t_object *object, t_point3 world_point)
{
	t_point3	object_p;
	t_point3	object_n;
	t_point3	world_n;

	object_p = tm4mul(m4invert(object->transform, 0), world_point);
	object_n = vsub(object_p, ((t_sphere *)object->data)->origin);
	world_n = tm4mul(m4transpose(m4invert(object->transform, 0)), object_n);
	world_n.w = VECTOR;
	vnormalize(&world_n);
	return (world_n);
}
