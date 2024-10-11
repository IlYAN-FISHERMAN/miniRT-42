#ifndef LIGHT_H
# define LIGHT_H

# include "objects.h"

typedef struct s_amb
{
	float	light;
	t_color	rgb;
	bool	is_calc;
	t_color	c_rgb;
}	t_amb;

typedef struct s_light
{
	t_point3	pos;
	t_color		rgb;
	float		bright;
	bool		is_calc;
	t_color		c_rgb;
}	t_light;

//  new_light: Create a new light object
//  @param pos The position of the light
//	@param rgb The color of the light
//	@param bright The brightness of the light
//  @return A new light object
t_object		*new_light(t_point3 pos, t_color rgb, float bright);

#endif
