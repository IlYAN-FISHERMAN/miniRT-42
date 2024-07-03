#include "sphere.h"

t_sphere	*new_raw_sphere(t_point3 origin, float radius)
{
	t_sphere	*sphere;

	sphere = galloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	sphere->origin = origin;
	sphere->radius = radius;
	return (sphere);
}

t_object	*new_sphere(t_point3 origin, float radius)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = new_raw_sphere(origin, radius);
	if (!sphere)
		return (0);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->type = o_sphere;
	object->data = sphere;
	return (object);
}

//	find_intersection: Find the intersection of a ray with a sphere
//	and store the result in the given intersection
//	@param intersect The intersection to store the result in
//	@param a The a value of the quadratic equation
//	@param b The b value of the quadratic equation
//	@param c The c value of the quadratic equation
//	@return true if the intersection was found, false otherwise
static bool	find_intersection(t_intersect *intersect, float a, float b, float c)
{
	float	discriminant;
	float	t1;
	float	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0f)
		return (false);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	if (t1 > RAY_T_MIN && t1 < intersect->t)
		intersect->t = t1;
	if (t2 > RAY_T_MIN && t2 < intersect->t)
		intersect->t = t2;
	else
		return (false);
}

bool	intersect_sphere(t_intersect *intersect, t_object *object)
{
	t_sphere	*sphere;
	t_ray		local_ray;
	float		a;
	float		b;
	float		c;

	sphere = (t_sphere *)object->data;
	local_ray.origin = vsub(intersect->ray.origin, sphere->origin);
	a = vlength2(intersect->ray.direction);
	b = 2.0f * vdot(local_ray.direction, local_ray.origin);
	c = vlength2(local_ray.origin) - (sphere->radius * sphere->radius);
	if (!find_intersection(intersect, a, b, c))
		return (false);
	intersect->object = object;
	return (true);
}

bool	does_intersect_sphere(t_ray ray, t_object *object)
{
	t_sphere	*sphere;
	t_ray		local_ray;
	float		a;
	float		b;
	float		c;

	sphere = (t_sphere *)object->data;
	local_ray.origin = vsub(ray.origin, sphere->origin);
	a = vlength2(ray.direction);
	b = 2.0f * vdot(local_ray.direction, ray.direction);
	c = vlength2(local_ray.origin) - (sphere->radius * sphere->radius);
	if (b * b - 4 * a * c < 0.0f)
		return (false);
	if ((-b - sqrt(b * b - 4 * a * c)) / (2 * a) > RAY_T_MIN
		&& (-b - sqrt(b * b - 4 * a * c)) / (2 * a) < RAY_T_MAX)
		return (true);
	if ((-b + sqrt(b * b - 4 * a * c)) / (2 * a) > RAY_T_MIN
		&& (-b + sqrt(b * b - 4 * a * c)) / (2 * a) < RAY_T_MAX)
		return (true);
	return (false);
}
