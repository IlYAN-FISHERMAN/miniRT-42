#include "sphere.h"

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
	t_calc_sphere	calc;

	inters = xs();
	calc.sphere2ray = vsub(ray.origin, point3(0, 0, 0));
	calc.a = vdot(ray.direction, ray.direction);
	calc.b = 2 * vdot(ray.direction, calc.sphere2ray);
	calc.c = vdot(calc.sphere2ray, calc.sphere2ray) - 1;
	calc.discriminant = calc.b * calc.b - 4 * calc.a * calc.c;
	if (calc.discriminant < -EPSILOND)
		return (inters);
	calc.disc_sqrt = sqrt(calc.discriminant);
	calc.t[0] = (-calc.b - calc.disc_sqrt) / (2 * calc.a);
	calc.t[1] = (-calc.b + calc.disc_sqrt) / (2 * calc.a);
	add_intersection(&inters, intersection(calc.t[0], object));
	if (!ft_equalsd(calc.discriminant, 0))
		add_intersection(&inters, intersection(calc.t[1], object));
	return (inters);
}

//  uv_mapping_sphere: Map a point on the sphere to a 2D UV coordinate
//  @param local_point The point on the sphere
//  @return The UV coordinate
static t_vector2	uv_mapping_sphere(t_point3 local_point)
{
	double	theta;
	double	phi;

	theta = atan2(local_point.x, local_point.z);
	phi = acos(local_point.y);
	return (vector2(1 - (theta + M_PI) / (2 * M_PI),
			phi / M_PI));
}

//  normal_at_sphere: Get the normal at a point on the sphere
//  @param object The object
//  @param local_point The point on the sphere
//  @return The normal at the point
static t_vector3	normal_at_sphere(t_object *object, t_point3 local_point)
{
	if (object->mat.bumpmap)
		return (perturbn(local_point, get_bumpv(object->mat.bumpmap,
					uv_mapping_sphere(local_point))));
	return (vsub(local_point, point3(0, 0, 0)));
}

t_object	*new_sphere(t_point3 origin, double radius, t_color color)
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
	*((t_sphere *)object->data) = (t_sphere){.origin = origin,
		.radius = radius};
	*object = (t_object){.data = object->data, .mat = dfmaterial(color),
		.local_intersect = intersect_sphere, .type = o_sphere,
		.local_normal_at = normal_at_sphere};
	object->transform = m4mul(m4translation(origin),
			m4scaling(vector3(radius, radius, radius)));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
