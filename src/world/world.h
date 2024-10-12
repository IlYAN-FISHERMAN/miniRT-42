#ifndef WORLD_H
# define WORLD_H

# include "../objects/objects.h"
# include "../objects/shape.h"

//  dfworld: Create a default world
//  @return The default world
//  @note This function is temporary and will be removed
t_scene		*dfworld(void);

//  get_next_light: Get the next light in the scene
//  @param scene The scene
//  @return The next light
t_object	*get_next_light(t_scene *scene);

//  intersect_world: Intersect the world with a ray
//  @param scene The scene to intersect with
//  @param ray The ray to intersect with
//  @return The intersection set of all objects in the world
t_xs_parent	intersect_world(t_scene *scene, t_ray ray);

#endif