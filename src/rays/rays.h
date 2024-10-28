/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:41 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:53:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "../matrix/matrix.h"

//	Define the minimum and maximum t values for the ray, preventing
//	the ray from intersecting with itself
# define RAY_T_MIN 0.0001f

typedef struct s_ray
{
	t_point3		origin;
	t_vector3		direction;
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

//	transform: Transform a ray by a matrix
//  @param r The ray to transform
//  @param m The matrix to transform the ray by
//  math: r.origin = m * r.origin
//  math: r.direction = m * r.direction
//  @return The transformed ray
t_ray		transform(t_ray r, t_matrix4 m);

#endif
