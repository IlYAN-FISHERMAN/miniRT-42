#ifndef INTERSECT_H
# define INTERSECT_H

# include "rays.h"
# include "../color/color.h"

typedef struct s_object	t_object;

typedef struct s_intersect
{
	float			t;
	t_object		*object;
}	t_intersect;

typedef struct s_xs_parent
{
	int			count;
	t_intersect	*xs;
}	t_xs_parent;

//	xs: Create a new intersection set
//	@return The new intersection set
t_xs_parent		xs(void);

//	intersection: Create a new intersection
//	@param t The t value of the intersection
//	@param object The object that was intersected
//	@return The new intersection
t_intersect		intersection(float t, t_object *object);

//	intersections: Create a new intersection set
//	@param i1 The first intersection
//	@param i2 The second intersection
//	@return The new intersection set
t_xs_parent		intersections(t_xs_parent xs_set);

//	hit: Find the closest intersection
//	@param xs The intersection set
//	@return The closest intersection or NULL if no valid intersection
t_intersect		*hit(t_xs_parent xs);

//	add_intersection: Add an intersection to the intersection set
//	@param xs The intersection set
//	@param i The intersection to add
//	@return The new intersection set
t_xs_parent		*add_intersection(t_xs_parent *xs, t_intersect i);

//	mergef_intersections: Merge two intersection sets and free the old sets
//	@param xs1 The first intersection set
//	@param xs2 The second intersection set
//	@return The merged intersection set
t_xs_parent		mergef_intersections(t_xs_parent xs1, t_xs_parent xs2);

#endif
