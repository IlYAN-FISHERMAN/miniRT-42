#ifndef INTERSECT_H
# define INTERSECT_H

# include "rays.h"

typedef struct intersect
{
	t_ray		ray;
	t_point		pos;
	float		t;
	t_object	*object;
}	t_intersect;

//	new_intersect: Create a new intersection
//  @param ray The ray that intersects with the object
//  @param The scalar value of the intersection
//  @param object The object that the ray intersects with
//  @return A new allocated intersection
t_intersect	*new_intersect(t_ray ray, float t, t_object *object);

#endif