#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/betterft/betterft.h"
# include "camera/camera.h"
# include "camera/image.h"
# include "objects/objects.h"
#include "vectors/vectors.h"

# define WIDTH 1920
# define HEIGHT 1080

//	minilibx include
# ifdef __APPLE__
#  include "../libs/minilibx_opengl/mlx.h"
# endif

# ifndef __APPLE__
#  include "../libs/minilibx-linux/mlx.h"
# endif

typedef struct s_win
{
	void	*mlx;
	void	*windo;
}	t_win;

typedef struct s_size
{
	int	height;
	int	width;
}	t_size;

typedef struct s_minirt
{
	int			fd;
	t_win		win;
	t_image		*size;
	t_scene		*scene;
	t_camera	*cam;
}	t_minirt;

//	init_minirt: Initialize the miniRT minirt structure
//	@param argc The number of arguments
//	@param argv The arguments
//	@return The new minirt structure
t_minirt	*init_minirt(t_minirt *minirt, int argc, char **argv);
void		*memcheck(t_minirt *minirt, void *new);
void		*init_minirt_mlx(t_minirt *minirt);

#endif
