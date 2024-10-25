#ifndef OBJECTS_H
# define OBJECTS_H

# include "betterft.h"
# include "../vectors/vectors.h"
# include "../rays/intersect.h"
# include "../color/color.h"
# include "patterns.h"
# include "bumpmap.h"

//	t_objects_type: The type of object
typedef enum e_objects_type
{
	o_plane,
	o_sphere,
	o_light,
	o_cylin,
	o_cone,
}	t_objects_type;

// t_scene: A linked list of objects
typedef t_list			t_scene;

// t_lights: A linked list of lights
typedef t_list			t_lights;

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
	t_bumpmap	*bumpmap;
}	t_mat;

//	t_object: An object in the scene
typedef struct s_object	t_object;

typedef struct s_object
{
	t_objects_type	type;
	void			*data;
	t_xs_parent			(*local_intersect)(t_object *, t_ray);
	t_vector3		(*local_normal_at)(t_object *, t_point3);
	t_matrix4		transform;
	t_matrix4		inv_transform;
	t_matrix4		tinv_transform;
	t_mat			mat;
}	t_object;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	t[2];
}	t_quadratic;

//	normal_at: Gets the normal of an object using world_point
//	@param obj The object to get the normal from
//	@param world_point The point to get the normal from
//	@return The normal of the object
t_vector3	normal_at(t_object *obj, t_point3 world_point);

//	intersect_at: Gets the intersections of an object using world ray
//	@param obj	The object to get the intersections from
//	@param ray	The ray to get the intersections from
//	@return The intersections of the object
t_xs_parent	intersect_at(t_object *obj, t_ray ray);

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

//	set_transform: Set the transformation matrix of an object
//	@param obj The object to transform
//	@param transform The transformation matrix
void		set_transform(t_object *obj, t_matrix4 transform);

//	quadratic_intersection: Calculate the intersection of a quadratic equation
//	@param quad The quadratic equation and the intersection
bool		quadratic_intersection(t_quadratic *quad);

#endif
