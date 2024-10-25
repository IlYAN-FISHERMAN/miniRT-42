#ifndef SPHERE_H
# define SPHERE_H

# include "objects.h"
# include "../vectors/vectors.h"

typedef struct s_sphere
{
	t_point3	origin;
	double		radius;
}	t_sphere;

typedef struct s_calc_sphere
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		disc_sqrt;
	t_point3	sphere2ray;
	double		t[2];
}	t_calc_sphere;

//  new_sphere: Create a new sphere object
//  @param origin The origin of the sphere
//  @param radius The radius of the sphere
//	@param color The color of the sphere
//  @return A new sphere object
t_object		*new_sphere(t_point3 origin, double radius, t_color color);

#endif
