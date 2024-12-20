/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:42:29 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:42:30 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "betterft.h"
# include "camera/render.h"
# include "camera/camera.h"
# include "camera/image.h"
# include "objects/objects.h"
# include "vectors/vectors.h"
# include "color/color.h"
# include "generator/rt_generate.h"
# include "objects/shape.h"
# include "compute/lightning.h"
# include "world/world.h"
# include "compute/compute.h"
# include "objects/material.h"

# define WIDTH 1920.0f
# define HEIGHT 1080.0f

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef BONUS
#  define BONUS 0
# endif

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

typedef struct s_world
{
	t_camera	*cam;
	t_scene		*scene;
	t_lights	*lights;
	t_amb		*amb;
}	t_world;

typedef struct s_minirt
{
	int			fd;
	t_win		win;
	t_image		*size;
	t_world		world;
	t_dfmat		df_mat;
	t_mats		*mat;
	bool		is_rendering;
	bool		update;
	int			is_first;
	pthread_t	*threads;
}	t_minirt;

//	init_minirt: Initialize the miniRT minirt structure
//	@param argc The number of arguments
//	@param argv The arguments
//	@return The new minirt structure
t_minirt	*init_minirt(t_minirt *minirt, int argc, char **argv);
//	get_minirt: Get the minirt structure as a static variable
//	@return The minirt structure
t_minirt	*get_minirt(void);
void		*init_minirt_mlx(t_minirt *minirt);
void		help_message(t_minirt *minirt);

#endif
