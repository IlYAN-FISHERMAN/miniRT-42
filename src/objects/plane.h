#ifndef PLANE_H
# define PLANE_H

# include "objects.h"

typedef struct s_plane
{
	t_point		origin;
	t_vector	normal;
}	t_plane;

//  new_raw_plane: Create a new plane
//  @param origin The origin of the plane
//  @param normal The normal of the plane
//  @return A new plane
t_plane		*new_raw_plane(t_point origin, t_vector normal);

//  new_plane: Create a new plane object
//  @param origin The origin of the plane
//  @param normal The normal of the plane
//  @return A new plane object
t_object	*new_plane(t_point origin, t_vector normal);

//  intersect_plane: Check if ray intersects plane and update intersection data
//  @param intersect The intersection data
//  @param object The object to check
//	math: t = (origin - ray.origin) . normal / (ray.direction . normal)
//  @return true if the ray intersects the plane, false otherwise
bool		intersect_plane(t_intersect *intersect, t_object *object);

//  does_intersect_plane: Check if a ray intersects a plane
//  @param ray The ray to check
//  @param object The object to check
//	math: t = (origin - ray.origin) . normal / (ray.direction . normal)
//  @return true if the ray intersects the plane, false otherwise
bool		does_intersect_plane(t_ray ray, t_object *object);

#endif