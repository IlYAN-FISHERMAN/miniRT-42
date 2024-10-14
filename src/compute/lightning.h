#ifndef LIGHTNING_H
# define LIGHTNING_H

# include "../objects/shape.h"

typedef struct s_lightning
{
	t_object	*l;
	t_point3	p;
	t_vector3	ev;
	t_vector3	nv;
	t_amb		*amb;
}	t_lightning;

//	new_lightning: Create a new lightning object
//	@param l The light object
//	@param p The point of intersection
//	@param ev The eye vector
//	@param nv The normal vector
//	@return A new lightning object
t_lightning		new_lightning(t_object *l, t_point3 p,
					t_vector3 ev, t_vector3 nv);
//	lightning: Calculate the lightning of an object
//	@param obj The object to calculate the lightning for
//	@param ln The lightning data
//	@param in_shadow If the object is in shadow
//	@param fast If the computation should be fast
//	@return The color of the object
t_color			lightning(t_object *obj, t_lightning ln,
					bool in_shadow, bool fast);

//	is_shadowed: Check if a point is in shadow
//	@param scene The scene
//	@param point The point to check
//	@param light The light object
//	@return true if the point is in shadow, false otherwise
bool			is_shadowed(t_scene *scene, t_point3 point, t_object *light);

#endif