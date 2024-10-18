#include "image.h"

t_image	*new_image(int width, int height)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (!image)
		return (0);
	image->width = width;
	image->height = height;
	return (image);
}
