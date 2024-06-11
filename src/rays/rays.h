#ifndef RAYS_H
# define RAYS_H

# include "../vectors/vectors.h"

//	Define the minimum and maximum t values for the ray, preventing the ray from intersecting with itself
#define RAY_T_MIN 0.0001f
//	Define the maximum t value for the ray
#define RAY_T_MAX 1.0e30f

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
	float		t;
}	t_ray;

typedef struct intersect
{
	t_ray		ray;
	t_point		point;
	float		t;
	int			*shape;
}	t_intersect;

//	ray_at: Calculate the point at a given t value along a ray
t_point	ray_at(t_ray ray, float t);

#endif