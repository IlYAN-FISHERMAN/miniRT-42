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

//  intersect_cylinder: Check if ray intersects cylinder
//  @param intersect The intersection data
//  @param object The object to check
//  @return true if the ray intersects the cylinder, false otherwise
static t_xs_parent	intersect_cylinder(t_object *object, t_ray ray)
{
	t_xs_parent	xs_parent;
	t_quadratic	q;
	t_point3	cyl2ray;

	xs_parent = xs();
	ray = transform(ray, object->inv_transform);
	cyl2ray = vsub(ray.origin, point3(0, 0, 0));
	q.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (ft_equalsd(q.a, 0))
		return (xs_parent);
	q.b = 2 * cyl2ray.x * ray.direction.x + 2 * cyl2ray.z * ray.direction.z;
	q.c = cyl2ray.x * cyl2ray.x + cyl2ray.z * cyl2ray.z - 1;
	if (!quadratic_intersection(&q))
		return (xs_parent);
	if (q.t[0] > q.t[1])
		ft_swap(&q.t[0], &q.t[1]);
	check_bounds(object, ray, &xs_parent, &q);
	intersect_caps(object, ray, &xs_parent);
	return (xs_parent);
}

//  uv_mapping_cylin: Map a point on the cylinder to a uv coordinate
//  @param object_point The point on the cylinder
//  @return The uv coordinate
static t_vector2	uv_mapping_cylin(t_point3 object_point)
{
	double		theta;
	double		y;

	y = object_point.y - floor(object_point.y);
	theta = atan2(object_point.z, object_point.x);
	return (vector2((theta + M_PI) / (2 * M_PI), y));
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
	if (object->mat.bumpmap)
		normal = perturbn(normal,
				get_bumpv(object->mat.bumpmap, uv_mapping_cylin(object_point)));
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
