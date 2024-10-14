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
