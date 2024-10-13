#include "camera.h"
#include "../miniRT.h"

void	process_camera(t_camera *camera)
{
	camera->aspect_ratio = camera->hsize / camera->vsize;
	camera->half_view = tanf(camera->fov_rad * 0.5);
	if (camera->aspect_ratio >= 1)
	{
		camera->half_width = camera->half_view;
		camera->half_height = camera->half_view / camera->aspect_ratio;
	}
	else
	{
		camera->half_width = camera->half_view * camera->aspect_ratio;
		camera->half_height = camera->half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
}

t_camera	*new_camera(t_point3 origin, t_vector3 target, float fov)
{
	t_camera	*camera;
	t_minirt	*minirt;

	origin.w = POINT;
	target.w = VECTOR;
	camera = galloc(sizeof(t_camera));
	if (!camera)
		return (0);
	minirt = get_minirt();
	*camera = (t_camera){.origin = origin, .target = target, .fov = fov,
		.fov_rad = fov * DEG2RADF, .vsize = minirt->size->height,
		.hsize = minirt->size->width,
		.transform = m4default()};
	camera->transform = view_transform(camera->origin, camera->target,
			vector3(0, 1, 0));
	camera->inv_transform = m4invert(camera->transform, 0);
	process_camera(camera);
	return (camera);
}

//	default upguide is (0, 1, 0)

t_matrix4	view_transform(t_point3 from, t_point3 to, t_vector3 up)
{
	t_vector3	forward;
	t_vector3	left;
	t_vector3	true_up;
	t_matrix4	orientation;

	forward = vnormalized(vsub(to, from));
	left = vcross(forward, vnormalized(up));
	true_up = vcross(left, forward);
	orientation = (t_matrix4){.data = {
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}
	}};
	return (m4mul(orientation,
			m4translation(point3(-from.x, -from.y, -from.z))));
}

t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	float			w_x;
	float			w_y;
	static t_point3	origin;
	static bool		origin_set = false;
	t_vector3		direction;

	w_x = camera->half_width - ((x + 0.5) * camera->pixel_size);
	w_y = camera->half_height - ((y + 0.5) * camera->pixel_size);
	if (!origin_set)
	{
		origin = tm4mul(camera->inv_transform, point3(0, 0, 0));
		origin_set = true;
	}
	direction = vnormalized(vsub(tm4mul(camera->inv_transform,
					point3(w_x, w_y, -1)), origin));
	return (ray(origin, direction));
}

void	render(void)
{
	t_minirt	*minirt;
	int			x;
	int			y;
	t_color		color;
	t_ray		r;

	y = -1;
	minirt = get_minirt();
	minirt->amb->c_rgb = color_scalar(minirt->amb->rgb, minirt->amb->light);
	minirt->amb->is_calc = true;
	while (++y, y < minirt->size->height)
	{
		x = -1;
		while (++x, x < minirt->size->width)
		{
			r = ray_for_pixel(minirt->cam, x, y);
			color = color_at(minirt->scene, minirt->amb, r);
			minirt->size->data[y][x] = color_hex(color);
		}
	}
}
