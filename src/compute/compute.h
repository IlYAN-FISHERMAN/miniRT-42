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
	t_vector3		reflectv;
}	t_comps;

//	precompute: Precompute the intersection
//	@param i The intersection
//	@param r The ray
//	@return The precomputed intersection
t_comps	precompute(t_intersect *i, t_ray r);

//	shade_hit: Shade the hit
//	@param comps The precomputed intersection
//	@param fast If the computation should be fast
//	@param remaining The remaining reflections
//	@return The color of the hit
t_color	shade_hit(t_comps comps, bool fast, int remaining);

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
t_color	reflected_color(t_comps comps, bool fast, int remaining);

#endif