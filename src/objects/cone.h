#ifndef CONE_H
# define CONE_H

# include "objects.h"
# include "cylinder.h"

typedef struct s_cone
{
	t_vector3	origin;
	t_vector3	normal;
	double		radius;
	double		height;
	t_color		rgb;
}	t_cone;

typedef struct s_calc_cone
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		disc_sqrt;
	double		height;
	bool		does_inter[2];
	double		t[2];
	double		y[2];
}	t_calc_cone;

//  new_cone: Create a new cone object
//  @param origin The origin of the cone
//  @param radius The radius of the cone
//	@param height The height of the cone
//	@param normal The normal of the cone
//	@param color The color of the cone
//	@note The cone implementation does not follows the book
//	implementation. If errors are found, refer to the book
//  @return A new cone object
t_object		*new_cone(t_point3 origin, double *rad_hei,
					t_vector3 normal, t_color color);

#endif
