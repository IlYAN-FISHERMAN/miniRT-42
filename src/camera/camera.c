#include "camera.h"

t_camera	*new_camera(t_point3 origin, t_vector3 target,
	float fov, float aspect)
{
	t_camera	*camera;
	t_vector3	upguide;

	camera = galloc(sizeof(t_camera));
	if (!camera)
		return (0);
	upguide = vector3(0, 1, 0);
	camera->origin = origin;
	camera->forward = vnormalized(vsub(target, origin));
	camera->right = vnormalized(vcross(camera->forward, upguide));
	camera->up = vcross(camera->right, camera->forward);
	camera->h = tanf((fov * (M_PI / 180.0f)) / 2.0f);
	camera->w = camera->h * aspect;
	camera->fov = fov;
	return (camera);
}

t_ray	make_ray(t_camera *camera, t_vector2 point)
{
	t_vector3	direction;

	direction = vadd(vadd(camera->forward, vmul(camera->right, point.x
					* camera->w)), vmul(camera->up, point.y * camera->h));
	return (ray(camera->origin, vnormalized(direction)));
}
