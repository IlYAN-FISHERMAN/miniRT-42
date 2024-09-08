#ifndef CYLINDER_H
# define CYLINDER_H

# include "objects.h"

typedef struct s_cylin
{
	t_vector3	origin;
	t_vector3	normal;
	double		diam;
	double		height;
	t_color		rgb;
}	t_cylin;

#endif
