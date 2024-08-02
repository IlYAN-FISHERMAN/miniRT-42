#ifndef LIGHT_H
# define LIGHT_H

# include "objects.h"

typedef struct s_light
{
	t_point3	origin;
	t_color		color;
	float		brightness;
}	t_light;

//  new_light: Create a new light object
//  @param origin The origin of the light
//  @param color The color of the light
//  @param brightness The brightness of the light
//  @return A new light object
t_object	*new_light(t_point3 origin, t_color color, float brightness);

#endif
