#include "cone.h"

//	intersect_caps: Check if the ray intersects the caps of the cone
//	@param obj The object to check
//	@param ray The ray to check
//	@param xs_parent The intersection data
static void	intersect_caps(t_object *obj, t_ray ray, t_xs_parent *xs_parent)
{
	double		t;

	if (ft_equalsd(ray.direction.y, 0))
		return ;
	t = (1 - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		add_intersection(xs_parent, intersection(t, obj));
}

//	check_bounds: Check if the intersection is within the bounds of the cone
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

//  intersect_cone: Check if ray intersects cone
//  @param intersect The intersection data
//  @param obj The object to check
//  @return true if the ray intersects the cone, false otherwise
static t_xs_parent	intersect_cone(t_object *obj, t_ray r)
{
	t_xs_parent	xs_parent;
	double		a;
	double		b;
	double		c;
	t_point3	con2ray;

	xs_parent = xs();
	r = transform(r, obj->inv_transform);
	con2ray = vsub(r.origin, point3(0, 0, 0));
	a = r.direction.x * r.direction.x - r.direction.y * r.direction.y
		+ r.direction.z * r.direction.z;
	b = 2 * con2ray.x * r.direction.x - 2 * con2ray.y * r.direction.y
		+ 2 * con2ray.z * r.direction.z;
	c = con2ray.x * con2ray.x - con2ray.y * con2ray.y
		+ con2ray.z * con2ray.z;
	if (!quadratic_intersection(a, b, c, obj))
		return (xs_parent);
	if (obj->t[0] > obj->t[1])
		ft_swap(&obj->t[0], &obj->t[1]);
	check_bounds(obj, r, &xs_parent);
	intersect_caps(obj, r, &xs_parent);
	return (xs_parent);
}

//  normal_at_cone: Get the normal at a point on the cone
//  @param obj The object
//  @param world_point The point on the cone
//  @return The normal at the point
static t_vector3	normal_at_cone(t_object *obj, t_point3 world_point)
{
	double		dist;
	t_point3	obj_point;
	t_vector3	normal;
	double		y;

	obj_point = tm4mul(obj->inv_transform, world_point);
	dist = obj_point.x * obj_point.x + obj_point.z * obj_point.z;
	if (dist < 1 && obj_point.y >= 1 - EPSILOND)
		normal = vector3(0, 1, 0);
	else if (dist < 1 && obj_point.y <= EPSILOND)
		normal = vector3(0, -1, 0);
	else
	{
		y = sqrt(dist);
		if (obj_point.y > 0)
			y = -y;
		normal = vector3(obj_point.x, y, obj_point.z);
	}
	normal = tm4mul(obj->tinv_transform, normal);
	vnormalize(&normal);
	return (normal);
}

t_object	*new_cone(t_point3 origin, double *rad_hei,
				t_vector3 normal, t_color color)
{
	t_object	*obj;

	origin.w = POINT;
	normal.w = VECTOR;
	vnormalize(&normal);
	obj = galloc(sizeof(t_object));
	if (!obj)
		return (0);
	obj->data = galloc(sizeof(t_cone));
	if (!obj->data)
	{
		gfree(obj);
		return (0);
	}
	*((t_cone *)obj->data) = (t_cone){.origin = origin,
		.radius = rad_hei[0], .height = rad_hei[1], .normal = normal};
	*obj = (t_object){.data = obj->data, .mat = dfmaterial(color),
		.transform = m4translation(origin), .intersect = intersect_cone,
		.type = o_cone, .normal_at = normal_at_cone};
	set_transform(obj, m4rotating_dir(point3(0, 1, 0), normal));
	set_transform(obj,
		m4scaling(vector3(rad_hei[0], rad_hei[1], rad_hei[0])));
	obj->inv_transform = m4invert(obj->transform, 0);
	obj->tinv_transform = m4transpose(obj->inv_transform);
	return (obj);
}
