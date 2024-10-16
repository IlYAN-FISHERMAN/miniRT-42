#ifndef CYLINDER_H
# define CYLINDER_H

# include "objects.h"

typedef struct s_cylin
{
	t_vector3	origin;
	t_vector3	normal;
	double		radius;
	double		height;
	t_color		rgb;
}	t_cylin;

//  new_cylinder: Create a new cylinder object
//  @param origin The origin of the cylinder
//  @param radius The radius of the cylinder
//	@param height The height of the cylinder
//	@param normal The normal of the cylinder
//  @return A new cylinder object
t_object		*new_cylinder(t_point3 origin, double *rad_hei,
					t_vector3 normal, t_color color);

//	check_cap: Check if the ray intersects the cap of the cylinder
//	@param ray The ray to check
//	@param t The distance to the cap
//	@return true if the ray intersects the cap, false otherwise
bool			check_cap(t_ray ray, double t);

#endif
