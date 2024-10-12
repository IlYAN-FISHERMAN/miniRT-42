#include "camera.h"
#include "../miniRT.h"

t_camera	*new_camera(t_point3 origin, t_vector3 target, float fov)
{
	t_camera	*camera;
	t_minirt	*minirt;

	camera = galloc(sizeof(t_camera));
	if (!camera)
		return (0);
	minirt = get_minirt();
	*camera = (t_camera){.origin = origin, .target = target, .fov = fov,
		.fov_rad = fov * DEG2RADF, .vsize = minirt->size->height,
		.hsize = minirt->size->width,
		.transform = m4default()};
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
	return (m4mul(orientation, m4translation(vneg(from))));
}

t_ray	ray_for_pixel(t_camera *camera, int x, int y)
{
	t_matrix4	inv;
	float		w_x;
	float		w_y;
	t_point3	origin;
	t_vector3	direction;

	w_x = camera->half_width - ((x + 0.5) * camera->pixel_size);
	w_y = camera->half_height - ((y + 0.5) * camera->pixel_size);
	inv = m4invert(camera->transform, 0);
	origin = tm4mul(inv, point3(0, 0, 0));
	direction = vnormalized(vsub(tm4mul(inv, point3(w_x, w_y, -1)), origin));
	return (ray(origin, direction));
}
