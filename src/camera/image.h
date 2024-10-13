#ifndef IMAGE_H
# define IMAGE_H

# include "camera.h"
# include "../objects/shape.h"

typedef struct s_image
{
	int		width;
	int		height;
	int		**data;
}	t_image;

typedef struct s_size
{
	int	height;
	int	width;
}	t_size;

//	new_image: Create a new image
//  @param width The width of the image
//  @param height The height of the image
//  @return A new allocated image
t_image	*new_image(int width, int height);

#endif
