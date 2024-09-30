#ifndef OBJECTS_H
# define OBJECTS_H

# include "betterft.h"
# include "../vectors/vectors.h"
# include "../rays/intersect.h"
# include "../color/color.h"

typedef struct s_intersections
{
	int			count;
	t_intersect data[10];
}	t_intersections;

//	t_objects_type: The type of object
typedef enum e_objects_type
{
	o_plane,
	o_sphere,
	o_light,
	o_cylin,
}	t_objects_type;

// t_scene: A linked list of objects
typedef t_list			t_scene;

//	t_object: An object in the scene
typedef struct s_object	t_object;
typedef struct s_object
{
	t_objects_type	type;
	void			*data;
	bool			(*intersect)(t_intersect *, t_object *);
	bool			(*does_intersect)(t_ray, t_object *);
}	t_object;

//	does_intersect: Check if a ray intersects any object in the object list
//	@param ray The ray to check
//	@param scene The object list to check
//	@return true if the ray intersects any object, false otherwise
bool	does_intersect(t_ray ray, t_scene *scene);

//	intersect: Check if a ray intersects any object in the object list
//	Also updates the intersection data
//	@param intersect The intersection data
//	@param scene The object list to check
//	@return true if the ray intersects any object, false otherwise
bool	intersect(t_intersect *intersect, t_scene *scene);

#endif
