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
//	@param material The object material
//  @return A new sphere object
t_object		*new_sphere(t_point3 origin, float radius, t_material material);

//  intersect_sphere: Check if ray intersects sphere and update
//  intersection data
//  @param intersect The intersection data
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the sphere, false otherwise
t_xs			intersect_sphere(t_object *object, t_ray ray);

//  does_intersect_sphere: Check if a ray intersects a sphere
//  @param ray The ray to check
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the sphere, false otherwise
bool			does_intersect_sphere(t_ray ray, t_object *object);

//  normal_at_sphere: Get the normal at a point on the sphere
//  @param object The object
//  @param world_point The point on the sphere
//  @return The normal at the point
t_vector3		normal_at_sphere(t_object *object, t_point3 world_point);

#endif
