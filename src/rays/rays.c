/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:45 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:53:47 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_point3	ray_at(t_ray ray, double t)
{
	return (vadd(ray.origin, vmul(ray.direction, t)));
}

t_ray	ray(t_point3 origin, t_vector3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_ray	transform(t_ray r, t_matrix4 m)
{
	t_ray	transformed;

	transformed.origin = tm4mul(m, r.origin);
	transformed.direction = tm4mul(m, r.direction);
	return (transformed);
}
