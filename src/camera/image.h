#ifndef IMAGE_H
# define IMAGE_H

# include "camera.h"
# include "../objects/shape.h"

typedef struct s_image
{
	double	width;
	double	height;
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

//	ray_trace: Trace rays through the scene
//	@param image The image to render to
//	@param camera The camera to render from
//	@param scene The scene to render
void	ray_trace(t_image *image, t_camera *camera, t_scene *scene);

#endif
