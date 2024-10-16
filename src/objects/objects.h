#ifndef OBJECTS_H
# define OBJECTS_H

# include "betterft.h"
# include "../vectors/vectors.h"
# include "../rays/intersect.h"
# include "../color/color.h"
# include "patterns.h"

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

typedef struct s_mat
{
	t_color		color;
	double		diff;
	double		spec;
	double		shin;
	double		reflect;
	double		transp;
	double		refract_idx;
	t_pattern	pattern;
}	t_mat;

//	t_object: An object in the scene
typedef struct s_object	t_object;

typedef struct s_object
{
	t_objects_type	type;
	void			*data;
	t_xs_parent			(*intersect)(t_object *, t_ray);
	t_vector3		(*normal_at)(t_object *, t_point3);
	t_matrix4		transform;
	t_matrix4		inv_transform;
	t_matrix4		tinv_transform;
	t_mat			mat;
	double			t[2];
}	t_object;

//	material: Create a new material
//	@param color The color value
//	@param diff The diffuse value
//	@param spec The specular value
//	@param shin The shininess value
//	@return A new material
t_mat		material(t_color color, double diff, double spec, double shin);

//	dfmaterial: Create a new default material
//	@param color The color value
//	@return A new default material
t_mat		dfmaterial(t_color color);

//	does_intersect: Check if a ray intersects any object in the object list
//	@param ray The ray to check
//	@param scene The object list to check
//	@return true if the ray intersects any object, false otherwise
bool		does_intersect(t_ray ray, t_scene *scene);

//	intersect: Check if a ray intersects any object in the object list
//	Also updates the intersection data
//	@param intersect The intersection data
//	@param scene The object list to check
//	@return true if the ray intersects any object, false otherwise
bool		intersect(t_intersect *intersect, t_scene *scene);

//	set_transform: Set the transformation matrix of an object
//	@param obj The object to transform
//	@param transform The transformation matrix
void		set_transform(t_object *obj, t_matrix4 transform);

//	quadratic_intersection: Calculate the intersection of a quadratic equation
//	@param a The a value of the quadratic equation
//	@param b The b value of the quadratic equation
//	@param c The c value of the quadratic equation
//	@param obj The object to check
bool		quadratic_intersection(double a, double b, double c, t_object *obj);

#endif
