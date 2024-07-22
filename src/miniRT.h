#ifndef MINIRT_H
# define MINIRT_H

# include "../libs/betterft/betterft.h"

//	minilibx include
# ifdef __APPLE__
#  include "../libs/minilibx_opengl/mlx.h"
# endif

# ifndef __APPLE__
#  include "../libs/minilibx-linux/mlx.h"
# endif

typedef struct s_minirt
{
	void	*mlx;
	void	*win;
}				t_minirt;

//	init_minirt: Initialize the miniRT minirt structure
//	@param argc The number of arguments
//	@param argv The arguments
//	@return The new minirt structure
t_minirt	*init_minirt(int argc, char **argv);

#endif