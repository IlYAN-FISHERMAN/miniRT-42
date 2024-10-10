#ifndef LIGHT_H
# define LIGHT_H

# include "objects.h"
# include "../vectors/vectors.h"

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

typedef struct s_lightning
{
	t_light		l;
	t_point3	p;
	t_vector3	ev;
	t_vector3	nv;
}	t_lightning;

//  new_light: Create a new light object
//  @param pos The position of the light
//	@param rgb The color of the light
//  @return A new light object
t_object		*new_light(t_point3 pos, t_color rgb);
//	new_lightning: Create a new lightning object
//	@param l The light object
//	@param p The point of intersection
//	@param ev The eye vector
//	@param nv The normal vector
//	@return A new lightning object
t_lightning		new_lightning(t_light l, t_point3 p,
					t_vector3 ev, t_vector3 nv);
//	lightning: Calculate the lightning of an object
//	@param obj The object to calculate the lightning for
//	@param amb The ambient data
//	@param ln The lightning data
//	@return The color of the object
t_color			lightning(t_object *obj, t_amb *amb, t_lightning ln);

#endif
