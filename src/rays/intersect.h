#ifndef INTERSECT_H
# define INTERSECT_H

# include "rays.h"

typedef struct s_object	t_object;

typedef struct intersect
{
	t_ray			ray;
	t_point3		pos;
	float			t;
	t_object		*object;
	bool			intersected;
}	t_intersect;

//	new_intersect: Create a new intersection
//  @param ray The ray that intersects with the object
//  @param The scalar value of the intersection
//  @param object The object that the ray intersects with
//  @return A new allocated intersection
t_intersect	*new_intersect(t_ray ray, float t, t_object *object);

#endif