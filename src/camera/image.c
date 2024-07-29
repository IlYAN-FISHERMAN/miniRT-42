#include "image.h"

static t_image	*allocate_image(t_image *image)
{
	int	i;

	i = -1;
	while (i++, i < image->height)
	{
		image->data[i] = galloc(sizeof(int) * image->width);
		if (!image->data[i])
		{
			while (i--)
				gfree(image->data[i]);
			gfree(image->data);
			return (0);
		}
	}
	return (image);
}

t_image	*new_image(int width, int height)
{
	t_image	*image;

	image = galloc(sizeof(t_image));
	if (!image)
		return (0);
	image->width = width;
	image->height = height;
	image->data = galloc(sizeof(int *) * height);
	if (!image->data)
	{
		gfree(image);
		return (0);
	}
	return (allocate_image(image));
}

void	ray_trace(t_image *image, t_camera *camera, t_scene *objects)
{
	t_intersect	inter;
	t_ray		ray;
	t_vector2	point;
	int			x;
	int			y;

	x = -1;
	while (x++, x < image->width)
	{
		y = -1;
		while (y++, y < image->height)
		{
			point = vector2((2.0f * x) / image->width - 1.0f,
					(-2.0f * y) / image->height + 1.0f);
			ray = make_ray(camera, point);
			inter.ray = ray;
			inter.t = RAY_T_MAX;
			inter.intersected = false;
			if (intersect(&inter, objects))
				image->data[y][x] = 1;
			else
				image->data[y][x] = 0;
		}
	}
}
