#include "camera.h"

t_camera	*new_camera(t_point3 origin, t_vector3 target, t_vector3 upguide)
{
	t_camera	*camera;

	camera = galloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->origin = origin;
	camera->forward = vnormalized(vsub(target, origin));
	camera->right = vnormalized(vcross(camera->forward, upguide));
	camera->up = vcross(camera->right, camera->forward);
	return (camera);
}

t_camera	*set_fov(t_camera *camera, float fov, float aspect)
{
	camera->h = tanf(fov);
	camera->w = camera->h * aspect;
	return (camera);
}

t_ray	make_ray(t_camera *camera, t_vector2 point)
{
	t_vector3	direction;

	direction = vadd(vadd(camera->forward, vmul(camera->right, point.u
					* camera->w)), vmul(camera->up, point.v * camera->h));
	return (ray(camera->origin, vnormalized(direction)));
}
