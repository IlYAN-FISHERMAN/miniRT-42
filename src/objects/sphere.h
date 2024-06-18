#ifndef SPHERE_H
# define SPHERE_H

# include "objects.h"
# include "../vectors/vectors.h"

typedef struct s_sphere {
	t_point	origin;
	float	radius;
}	t_sphere;

//  new_raw_sphere: Create a new sphere
//  origin: The origin of the sphere
//  radius: The radius of tshe sphere
//  Returns: A new sphere
t_sphere	*new_raw_sphere(t_point origin, float radius);

//  new_sphere: Create a new sphere object
//  origin: The origin of the sphere
//  radius: The radius of the sphere
//  Returns: A new sphere object
t_object	*new_sphere(t_point origin, float radius);

#endif