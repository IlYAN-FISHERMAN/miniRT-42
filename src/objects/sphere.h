#ifndef SPHERE_H
# define SPHERE_H

# include "objects.h"
# include "../vectors/vectors.h"

typedef struct s_sphere
{
	t_point3	origin;
	float		radius;
}	t_sphere;

//  new_sphere: Create a new sphere object
//  @param origin The origin of the sphere
//  @param radius The radius of the sphere
//	@param color The color of the sphere
//  @return A new sphere object
t_object		*new_sphere(t_point3 origin, float radius, t_color color);

#endif
