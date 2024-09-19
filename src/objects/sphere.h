#ifndef SPHERE_H
# define SPHERE_H

# include "objects.h"
# include "../vectors/vectors.h"

typedef struct s_sphere
{
	t_point3	origin;
	float		radius;
	t_color		color;	
}	t_sphere;

//  new_raw_sphere: Create a new sphere
//  @param origin The origin of the sphere
//  @param radius The radius of tshe sphere
//  @return A new sphere
t_sphere	*new_raw_sphere(t_point3 origin, float radius, t_color color);

//  new_sphere: Create a new sphere object
//  @param origin The origin of the sphere
//  @param radius The radius of the sphere
//  @return A new sphere object
t_object	*new_sphere(t_point3 origin, float radius, t_color color);

//  intersect_sphere: Check if ray intersects sphere and update
//	intersection data
//  @param intersect The intersection data
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the sphere, false otherwise
bool		intersect_sphere(t_intersect *intersect, t_object *object);

//  does_intersect_sphere: Check if a ray intersects a sphere
//  @param ray The ray to check
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the sphere, false otherwise
bool		does_intersect_sphere(t_ray ray, t_object *object);

#endif
