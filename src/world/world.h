/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:54:17 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:54:19 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../objects/objects.h"
# include "../objects/shape.h"

//  intersect_world: Intersect the world with a ray
//  @param scene The scene to intersect with
//  @param ray The ray to intersect with
//  @return The intersection set of all objects in the world
t_xs_parent	intersect_world(t_scene *scene, t_ray ray);

#endif