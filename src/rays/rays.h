#ifndef RAYS_H
# define RAYS_H

# include "../vectors/vectors.h"

//	Define the minimum and maximum t values for the ray, preventing
//	the ray from intersecting with itself
# define RAY_T_MIN 0.0001f
//	Define the maximum t value for the ray
# define RAY_T_MAX 1.0e30f

typedef struct s_ray
{
	t_point3		origin;
	t_vector3		direction;
	double			t;
}	t_ray;

//	ray: Create a new stack-allocated ray
//  @param origin The origin of the ray
//  @param direction The direction of the ray
//  @return A new ray
t_ray		ray(t_point3 origin, t_vector3 direction);

//	ray_at: Calculate the point at a given t value along a ray
//  @param ray The ray to calculate the point along
//  @param t The t value to calculate the point at
//  math: p + t * d
//  @return The point at the given t value along the ray
t_point3	ray_at(t_ray ray, double t);

#endif
