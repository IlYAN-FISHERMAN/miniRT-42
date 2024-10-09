#ifndef LIGHT_H
# define LIGHT_H

# include "objects.h"
# include "../vectors/vectors.h"

typedef struct s_light
{
	t_point3	origin;
	t_color		color;	
}	t_light;

//  new_light: Create a new light object
//  @param origin The origin of the light
//  @param radius The radius of the light
//  @return A new light object
t_object		*new_light(t_point3 origin, t_color color);

#endif
