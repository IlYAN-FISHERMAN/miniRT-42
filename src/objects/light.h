#ifndef LIGHT_H
# define LIGHT_H

# include "objects.h"
# include "../vectors/vectors.h"

typedef struct s_light
{
	t_point3	origin;
	t_color		color;	
}	t_light;

//  new_light: Create a new light object
//  @param origin The origin of the light
//  @param radius The radius of the light
//  @return A new light object
t_object		*new_light(t_point3 origin, float radius, t_color color);

//  intersect_light: Check if ray intersects light and update
//  intersection data
//  @param intersect The intersection data
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the light, false otherwise
t_xs	intersect_light(t_object *object, t_ray ray);

//  does_intersect_light: Check if a ray intersects a light
//  @param ray The ray to check
//  @param object The object to check
//	math: if t1 > RAY_T_MIN && t1 < intersect->t, intersect->t = t1
//	math: if t2 > RAY_T_MIN && t2 < intersect->t, intersect->t = t2
//  @return true if the ray intersects the light, false otherwise
bool			does_intersect_light(t_ray ray, t_object *object);

//  normal_at_light: Get the normal at a point on the light
//  @param object The object
//  @param world_point The point on the light
//  @return The normal at the point
t_vector3		normal_at_light(t_object *object, t_point3 world_point);

#endif
