#ifndef LIGHTNING_H
# define LIGHTNING_H

# include "../objects/shape.h"

typedef struct s_lightning
{
	t_object	*l;
	t_point3	p;
	t_vector3	ev;
	t_vector3	nv;
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
//	@param amb The ambient data
//	@param ln The lightning data
//	@return The color of the object
t_color			lightning(t_object *obj, t_amb *amb, t_lightning ln);

#endif