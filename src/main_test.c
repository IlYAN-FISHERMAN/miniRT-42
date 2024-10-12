#include "camera/image.h"
#include "parsing/parsing.h"
#include "miniRT.h"
/*
int	main(void)
{
	t_image		*image;
	t_camera	*camera;
	t_scene		*scene;

	image = new_image(WIDTH, HEIGHT);
	if (!image)
		return (1);
	camera = new_camera(point3(5, 1, 0), vector3(0, 1, 0), 90, WIDTH / HEIGHT);
	if (!camera)
	{
		gfree(image->data);
		gfree(image);
		return (1);
	}
	scene = ft_lstnew_back(0, new_plane(point3(0, 0, 0), vector3(0, 1, 0), color(255, 255, 255)));
	ft_lstnew_back(scene, new_sphere(point3(0, 2.5, 0), 2.1, color(255, 0, 0)));
	ft_lstnew_back(scene, new_sphere(point3(0, 0, -2.8), 1.5, color(0, 255, 0)));
	ray_trace(image, camera, scene);
	t_minirt	minirt;
	minirt.size = galloc(sizeof(t_image));
	minirt.size->height = HEIGHT;
	minirt.size->width = WIDTH;
	init_minirt_mlx(&minirt);
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			int color = image->data[j][i];
			mlx_pixel_put(minirt.win.mlx, minirt.win.windo, i, j, color);
		}
	}
	mlx_loop(minirt.win.mlx);
	gfree(image->data);
	gfree(image);
	gfree(camera);
	ft_lstclear(&scene, gfree);
	return (0);
}
*/


/*int    main(int argc, char **argv)
{
	t_point3	ray_origin;
	float		wall_z;
	float		canvas_pixels;
	float		pixel_size;
	float		wall_size;
	float		half;
	t_image		*image;
	t_object	*shape;
	t_object	*light;
	t_amb		amb;
	t_minirt	minirt;

	ft_bzero(&minirt, sizeof(minirt));
	init_minirt(&minirt, argc, argv);
	init_minirt_mlx(&minirt);
	t_scene	*scene;
	scene = minirt.scene;
	while (scene && ((t_object *)scene->content)->type != o_sphere)
		scene = scene->next;
	if (scene)
		shape = scene->content;
	scene = minirt.scene;
	print_token(&minirt, scene);
	while (scene && ((t_object *)scene->content)->type != o_light)
		scene = scene->next;
	if (scene)
		light = scene->content;
	else
		exit(1);
	amb = *minirt.amb;
	print_token(&minirt, scene);
	printf("%d %d %d\n", ((t_light *)light->data)->rgb.r, ((t_light *)light->data)->rgb.g, ((t_light *)light->data)->rgb.b);
	ray_origin = point3(0, 0, -10);
	wall_z = 10;
	wall_size = 7;
	canvas_pixels = 500;
	pixel_size = wall_size / canvas_pixels;
	half = wall_size / 2;
	image = new_image(canvas_pixels, canvas_pixels);
	for (int y = 0; y < canvas_pixels; y++)
	{
		float world_y = half - pixel_size * y;
		for (int x = 0; x < canvas_pixels; x++)
		{
			float world_x = -half + pixel_size * x;
			t_point3 position = point3(world_x, world_y, wall_z);
			t_ray r = ray(ray_origin, vnormalized(vsub(position, ray_origin)));
			t_xs_parent xs = shape->intersect(shape, r);
			if (hit(xs))
			{
				float t = xs.xs[0].t;
				t_point3 point = ray_at(r, t);
				t_vector3 normal = shape->normal_at(shape, point);
				t_vector3 eye = vneg(r.direction);
				t_lightning ln = new_lightning(*((t_light *)light->data), point, eye, normal);
				t_color c = lightning(shape, &amb, ln);
				image->data[y][x] = color_hex(c);
			}
		}
	}
	void *mlx_img = mlx_new_image(minirt.win.mlx, canvas_pixels, canvas_pixels);
	if (!mlx_img)
	{
		printf("Error: mlx_new_image failed\n");
		exit(1);
	}
	int bits_per_pixel, size_line, endian;
	char *img_data = mlx_get_data_addr(mlx_img, &bits_per_pixel, &size_line, &endian);
	for (int i = 0; i < canvas_pixels; i++)
	{
		for (int j = 0; j < canvas_pixels; j++)
		{
			if (!image->data[j][i])
				continue;
			int color = mlx_get_color_value(minirt.win.mlx, image->data[j][i]);
			int pixel_index = (j * size_line) + (i * (bits_per_pixel / 8));
			*(int *)(img_data + pixel_index) = color;
		}
	}
	mlx_put_image_to_window(minirt.win.mlx, minirt.win.windo, mlx_img, 0, 0);
	mlx_loop(minirt.win.mlx);
	gfree(image->data);
	gfree(image);
	gfree(shape);
	return (0);
}
*/

t_scene	*test_scene(void)
{
	t_scene		*scene;
	t_object	*s1;
	t_object	*s2;

	s1 = new_sphere(point3(0, 0, 0), 1,
			color(byte_clamp(255 * 0.8), 255, byte_clamp(255 * 0.6)));
	s1->mat.diff = 0.7;
	s1->mat.spec = 0.2;
	s2 = new_sphere(point3(0, 0, 0), 1, color(255, 51, 255));
	set_transform(s2, m4scaling(vector3(0.5, 0.5, 0.5)));
	scene = ft_calloc(1, sizeof(t_scene));
	scene->content = s1;
	scene->next = ft_calloc(1, sizeof(t_scene));
	scene->next->content = s2;
	return (scene);
}

void	render(t_scene *scene)
{
	t_xs_parent	xs_parent;
	t_ray		r;

	scene = test_scene();
	r = ray(point3(0, 0, -5), vector3(0, 0, 1));
	xs_parent = intersect_world(scene, r);
	printf("xs_parent.count: %d\n", xs_parent.count);
	for (int i = 0; i < xs_parent.count; i++)
	{
		printf("xs_parent.xs[%d].t: %f\n", i, xs_parent.xs[i].t);
	}
}

/*void	test_precompute(void)
{
	t_object	*shape;
	t_ray		r;
	t_intersect	i;
	t_comps		comps;

	shape = new_sphere(point3(0, 0, 0), 1, color(255, 0, 0));
	r = ray(point3(0, 0, 0), vector3(0, 0, 1));
	i = intersection(1, shape);
	comps = precompute(&i, r);
	printf("comps.t: %f\n", comps.t);
	printf("comps.object: %p, expected: %p\n", comps.object, shape);
	printf("comps.point: %f, %f, %f\n", comps.point.x, comps.point.y, comps.point.z);
	printf("comps.eyev: %f, %f, %f\n", comps.eyev.x, comps.eyev.y, comps.eyev.z);
	printf("comps.normalv: %f, %f, %f\n", comps.normalv.x, comps.normalv.y, comps.normalv.z);
	printf("comps.inside: %d\n", comps.inside);
}*/

/*void	test_shade_hit(void)
{
	t_scene		*scene;
	t_intersect	i;
	t_comps		comps;
	t_color		c;
	t_amb		amb;
	t_object	*light;

	scene = dfworld();
	i = intersection(0.5, scene->next->content);
	comps = precompute(&i, ray(point3(0, 0, 0), vector3(0, 0, 1)));
	amb = (t_amb){.rgb = color(255, 255, 255), .light = 0.1, .is_calc = false};
	light = ft_lstlast(scene)->content;
	gfree(light->data);
	gfree(light);
	light = new_light(point3(0, 0.25, 0), color(255, 255, 255), 1);
	ft_lstlast(scene)->content = light;
	c = shade_hit(scene, &amb, comps);
	printf("c.r: %d, c.g: %d, c.b: %d\n", c.r, c.g, c.b);
}*/

/**void	test_color_at(void)
{
	t_scene		*scene;
	t_ray		r;
	t_color		c;
	t_amb		amb;

	scene = dfworld();
	r = ray(point3(0, 0, 0.75), vector3(0, 0, -1));
	amb = (t_amb){.rgb = color(255, 255, 255), .light = 1, .is_calc = false};
	c = color_at(scene, &amb, r);
	printf("c.r: %d, c.g: %d, c.b: %d\n", c.r, c.g, c.b);
	printf("normalized colors:\n%f\n%f\n%f\n",
		c.r / 255.0, c.g / 255.0, c.b / 255.0);
}
**/

/*void	test_view_transform(void)
{
t_matrix4	vt;
	t_matrix4	expected;

	vt = view_transform(point3(0, 0, 8), point3(0, 0, 0), vector3(0, 1, 0));
	expected = m4translation(vector3(0, 0, -8));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (!ft_equalsf(vt.data[i][j], expected.data[i][j]))
				printf("%svt.data[%d][%d]: %f, expected: %f%s\n", C_RED, i, j, vt.data[i][j], expected.data[i][j], C_RESET);
			else
			{
				printf("%svt.data[%d][%d]: %f\t%s", C_GREEN, i, j, vt.data[i][j], C_RESET);
				printf("expected: %f\n", expected.data[i][j]);
			}
		}
	}
}*/

void	test_camera(void)
{
	t_camera	*camera;
	t_ray		r;

	camera = new_camera(point3(0, 0, 0), vector3(0, 0, -1), 90);
	camera->transform = m4mul(m4rotating(M_PI / 4, Y_AXIS), m4translation(vector3(0, -2, 5)));
	r = ray_for_pixel(camera, 100, 50);
	printf("canvas width: %f\n", camera->hsize);
	printf("canvas height: %f\n", camera->vsize);
	printf("r.origin = point3(%f, %f, %f)\n", r.origin.x, r.origin.y, r.origin.z);
	printf("r.direction = vector3(%f, %f, %f)\n", r.direction.x, r.direction.y, r.direction.z);
}

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	ft_bzero(&minirt, sizeof(minirt));
	init_minirt(&minirt, argc, argv);
	init_minirt_mlx(&minirt);
	//render(minirt.scene);
	test_camera();
	exit(0);
	mlx_loop(minirt.win.mlx);
	exit(0);
}