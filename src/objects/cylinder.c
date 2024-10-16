#include "cylinder.h"

//	intersect_caps: Check if the ray intersects the caps of the cylinder
//	@param object The object to check
//	@param ray The ray to check
//	@param xs_parent The intersection data
static void	intersect_caps(t_object *object, t_ray ray, t_xs_parent *xs_parent)
{
	double		t;

	if (ft_equalsd(ray.direction.y, 0))
		return ;
	t = (0 - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		add_intersection(xs_parent, intersection(t, object));
	t = (1 - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		add_intersection(xs_parent, intersection(t, object));
}

//	check_bounds: Check if the intersection is within the bounds of the cylinder
//	@param obj The object to check
//	@param ray The ray to check
//	@param xs_parent The intersection data
static	void	check_bounds(t_object *obj, t_ray ray,
	t_xs_parent *xs_parent)
{
	double		y[2];

	y[0] = ray.origin.y + obj->t[0] * ray.direction.y;
	if (y[0] < 1 && y[0] > 0)
		add_intersection(xs_parent, intersection(obj->t[0], obj));
	y[1] = ray.origin.y + obj->t[1] * ray.direction.y;
	if (y[1] < 1 && y[1] > 0)
		add_intersection(xs_parent, intersection(obj->t[1], obj));
}

//  intersect_cylinder: Check if ray intersects cylinder
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the cylinder, false otherwise
static t_xs_parent	intersect_cylinder(t_object *object, t_ray ray)
{
	t_xs_parent	xs_parent;
	double		a;
	double		b;
	double		c;
	t_point3	cyl_to_ray;

	xs_parent = xs();
	ray = transform(ray, object->inv_transform);
	cyl_to_ray = vsub(ray.origin, point3(0, 0, 0));
	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (ft_equalsd(a, 0))
		return (xs_parent);
	b = 2 * cyl_to_ray.x * ray.direction.x + 2 * cyl_to_ray.z * ray.direction.z;
	c = cyl_to_ray.x * cyl_to_ray.x + cyl_to_ray.z * cyl_to_ray.z - 1;
	if (!quadratic_intersection(a, b, c, object))
		return (xs_parent);
	if (object->t[0] > object->t[1])
		ft_swap(&object->t[0], &object->t[1]);
	check_bounds(object, ray, &xs_parent);
	intersect_caps(object, ray, &xs_parent);
	return (xs_parent);
}

//  normal_at_cylinder: Get the normal at a point on the cylinder
//  @param object The object
//  @param world_point The point on the cylinder
//  @return The normal at the point
static t_vector3	normal_at_cylinder(t_object *object, t_point3 world_point)
{
	double		dist;
	double		height;
	t_point3	object_point;
	t_vector3	normal;

	object_point = tm4mul(object->inv_transform, world_point);
	height = 1;
	dist = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dist < 1 && object_point.y >= height - EPSILOND)
		normal = vector3(0, 1, 0);
	else if (dist < 1 && object_point.y <= EPSILOND)
		normal = vector3(0, -1, 0);
	else
		normal = vector3(object_point.x, 0, object_point.z);
	normal = tm4mul(object->tinv_transform, normal);
	normal.w = VECTOR;
	vnormalize(&normal);
	return (normal);
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
	set_transform(object, m4rotating_dir(point3(0, 1, 0), normal));
	set_transform(object,
		m4scaling(vector3(rad_hei[0], rad_hei[1], rad_hei[0])));
	object->inv_transform = m4invert(object->transform, 0);
	object->tinv_transform = m4transpose(object->inv_transform);
	return (object);
}
