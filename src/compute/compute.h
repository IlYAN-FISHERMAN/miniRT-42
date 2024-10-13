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
}	t_comps;

//    precompute: Precompute the intersection
//    @param i The intersection
//    @param r The ray
//    @return The precomputed intersection
t_comps	precompute(t_intersect *i, t_ray r);

//    shade_hit: Shade the hit
//    @param scene The scene
//    @param amb The ambient data
//    @param comps The precomputed intersection
//    @return The color of the hit
t_color	shade_hit(t_scene *scene, t_amb *amb, t_comps comps);

//    color_at: Get the color at a point
//    @param scene The scene
//    @param amb The ambient data
//    @param r The ray
//    @return The color at the point
t_color	color_at(t_scene *scene, t_amb *amb, t_ray r);

#endif