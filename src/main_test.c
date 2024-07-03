#include "camera/image.h"

int	main(void)
{
	t_image		*image;
	t_camera	*camera;
	t_scene		*scene;

	image = new_image(200, 40);
	if (!image)
		return (1);
	camera = new_camera(point3(5, 1, 0), vector3(0, 1, 0), vector3(0, 1, 0));
	if (!camera)
	{
		gfree(image->data);
		gfree(image);
		return (1);
	}
	set_fov(camera, M_PI / 4.0f, 200.0f / 40.0f);
	scene = ft_lstadd(0, new_plane(point3(0, 0, 0), vector3(0, 1, 0)));
	scene->next = ft_lstadd(scene->next, new_sphere(point3(0, 1, 0), 2));
	ray_trace(image, camera, scene);
	print_image(image);
	gfree(image->data);
	gfree(image);
	gfree(camera);
	ft_lstclear(&scene, gfree);
	return (0);
}
