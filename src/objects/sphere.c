#include "sphere.h"

t_sphere	*new_raw_sphere(t_point3 origin, float radius, t_color color)
{
	t_sphere	*sphere;

	sphere = galloc(sizeof(t_sphere));
	if (!sphere)
		return (0);
	(*sphere) = (t_sphere){
		.origin = origin,
		.radius = radius,
		.color = color
	};
	return (sphere);
}

t_object	*new_sphere(t_point3 origin, float radius, t_color color)
{
	t_sphere	*sphere;
	t_object	*object;

	sphere = new_raw_sphere(origin, radius, color);
	if (!sphere)
		return (0);
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	(*object) = (t_object){
		.type = o_sphere,
		.data = sphere,
		.intersect = intersect_sphere,
		.does_intersect = does_intersect_sphere
	};
	return (object);
}

//	find_intersection: Find the intersection of a ray with a sphere
//	and store the result in the given intersection
//	@param inter The intersection to store the result in
//	@param a The a value of the quadratic equation
//	@param b The b value of the quadratic equation
//	@param c The c value of the quadratic equation
static void	find_intersection(t_intersections *inters, float a, float b, float c)
{
	float	discriminant;
	float	t1;
	float	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0f)
		return ;
	t1 = (-b - sqrtf(discriminant)) / (2 * a);
	t2 = (-b + sqrtf(discriminant)) / (2 * a);
	if (t1 > RAY_T_MIN && t1 < RAY_T_MAX)
	{
		// may need to just return t1 and t2, check performances
		inters->xs[0] = t1;
		inters->xs[1] = t2;
		inters->count = 2;
	}
}



t_intersections	intersect_sphere(t_object *object, t_ray ray)
{
	t_intersections	inters;
	t_sphere		*sphere;
	float			a;
	float			b;
	float			c;

	ft_bzero(&inters, sizeof(t_intersections));
	sphere = (t_sphere *)object->data;
	a = vdot(ray.direction, ray.direction);
	b = 2 * (vdot(ray.direction, ray.origin));
	c = vdot(ray.origin, ray.origin) - 1;
	find_intersection(&inters, a, b, c);
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
