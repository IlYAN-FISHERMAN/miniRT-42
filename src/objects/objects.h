#ifndef OBJECTS_H
# define OBJECTS_H

# include "../../libs/betterft/betterft.h"
# include "../vectors/vectors.h"
# include "../rays/intersect.h"

//	t_objects_type: The type of object
typedef enum e_objects_type
{
	o_plane,
	o_sphere,
}	t_objects_type;

// t_objects: A linked list of objects
typedef struct s_objects	t_objects;
typedef struct s_objects
{
	t_object	*content;
	t_objects	*next;
	t_objects	*prev;
}	t_objects;

//	t_object: An object in the scene
typedef struct s_object
{
	t_objects_type	type;
	void			*data;
	bool			(*intersect)(t_intersect *intersect, t_object *object);
	bool			(*does_intersect)(t_ray ray, t_object *object);
}	t_object;

//	does_intersect: Check if a ray intersects any object in the object list
//	Also updates the intersection data
//	@param intersect The intersection data
//	@param objects The object list to check
//	@return true if the ray intersects any object, false otherwise
bool	does_intersect(t_intersect *intersect, t_objects *objects);

//	intersect: Check if a ray intersects any object in the object list
//	@param ray The ray to check
//	@param objects The object list to check
//	@return true if the ray intersects any object, false otherwise
bool	intersect(t_ray ray, t_objects *objects);

#endif