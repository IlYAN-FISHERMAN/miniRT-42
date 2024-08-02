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
	camera->forward = vnormalized(target);
	camera->right = vmul(vnormalized(vcross(camera->forward, upguide)), -1);
	camera->up = vmul(vcross(camera->right, camera->forward), -1);
	camera->h = tanf((fov * (M_PI / 180.0f)) / 2.0f);
	camera->w = camera->h * aspect;
	return (camera);
}

t_color	get_shade(t_scene *scene, t_object *object, t_intersect *intersect)
{
	t_light		*light;

	(void)light;
	(void)object;
	if (vdot(vmul(intersect->ray.direction, -1), intersect->normal) < 0)
		intersect->normal = vmul(intersect->normal, -1);
	while (scene)
	{
		if (((t_object *)scene->content)->type != o_light)
		{
			scene = scene->next;
			continue ;
		}
		light = (t_light *)((t_object *)scene->content)->data;
	}
	return (intersect->color);
}

t_ray	make_ray(t_camera *camera, t_vector2 point)
{
	t_vector3	direction;

	direction = vadd(vadd(camera->forward, vmul(camera->right, point.u
					* camera->w)), vmul(camera->up, point.v * camera->h));
	return (ray(camera->origin, vnormalized(direction), RAY_T_MAX));
}
