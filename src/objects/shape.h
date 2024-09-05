#ifndef SHAPE_H
# define SHAPE_H

# include "../color/color.h"
# include "../vectors/vectors.h"
# include "objects.h"
# include "plane.h"
# include "sphere.h"

typedef struct s_amb
{
	float	light;
	t_color	rgb;
}	t_amb;

typedef struct s_light
{
	t_point3	pos;
	float		bright;
	t_color		rgb;
}	t_light;

#endif
