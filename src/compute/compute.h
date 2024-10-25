#ifndef COMPUTE_H
# define COMPUTE_H

# include "../objects/objects.h"
# include "lightning.h"
# include "../world/world.h"

typedef struct s_comps
{
	double			t;
	t_object		*object;
	t_point3		point;
	t_vector3		eyev;
	t_vector3		normalv;
	bool			inside;
	t_point3		over_point;
	t_point3		under_point;
	t_vector3		reflectv;
	double			n1;
	double			n2;
	t_list			*objs;
	t_object		*last_obj;
	double			cos_i;
	double			n_ratio;
	double			sin2_t;
	double			cos_t;
}	t_comps;

//	color_at: Get the color at a point
//	@param r The ray
//	@param fast If the computation should be fast
//	@param remaining The remaining reflections
//	@return The color at the point
t_color	color_at(t_ray r, bool fast, int remaining);

//	reflected_color: Get the reflected color
//	@param comps The precomputed intersection
//	@param fast If the computation should be fast
//	@param remaining The remaining reflections
//	@return The reflected color
t_color	reflected_color(t_comps *comps, bool fast, int remaining);

//	refracted_color: Get the refracted color
//	@param comps The precomputed intersection
//	@param fast If the computation should be fast
//	@param remaining The remaining reflections
//	@return The refracted color
t_color	refracted_color(t_comps *comps, bool fast, int remaining);

//	schlick: Compute the Schlick approximation
//	@param comps The precomputed intersection
//	@return The Schlick approximation
double	schlick(t_comps *comps);

#endif