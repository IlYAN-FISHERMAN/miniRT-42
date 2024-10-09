#ifndef SHAPE_H
# define SHAPE_H

# include "../color/color.h"
# include "../vectors/vectors.h"
# include "objects.h"
# include "plane.h"
# include "sphere.h"
# include "light.h"

typedef struct s_amb
{
	float	light;
	t_color	rgb;
}	t_amb;

#endif
