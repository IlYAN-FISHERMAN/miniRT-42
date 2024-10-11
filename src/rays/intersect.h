#ifndef INTERSECT_H
# define INTERSECT_H

# include "rays.h"
# include "../color/color.h"

typedef struct s_object	t_object;

typedef struct s_intersect
{
	t_ray			ray;	// may remove
	t_point3		pos;	// may remove
	float			t;
	t_object		*object;
	bool			intersected;	// may remove
	t_color			color;	// may remove
}	t_intersect;

typedef struct s_xs
{
	int			count;
	t_intersect	*xs;
}	t_xs;

//	xs: Create a new intersection set
//	@return The new intersection set
t_xs		xs(void);

//	intersection: Create a new intersection
//	@param t The t value of the intersection
//	@param object The object that was intersected
//	@return The new intersection
t_intersect	intersection(float t, t_object *object);

//	intersections: Create a new intersection set
//	@param i1 The first intersection
//	@param i2 The second intersection
//	@return The new intersection set
t_xs		intersections(t_xs xs_set);

//	hit: Find the closest intersection
//	@param xs The intersection set
//	@return The closest intersection or NULL if no valid intersection
t_intersect	*hit(t_xs xs);

//	add_intersection: Add an intersection to the intersection set
//	@param xs The intersection set
//	@param i The intersection to add
//	@return The new intersection set
t_xs		*add_intersection(t_xs *xs, t_intersect i);

#endif
