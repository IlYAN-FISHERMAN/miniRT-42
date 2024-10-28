/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:54:12 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:54:13 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_xs_parent	intersect_world(t_scene *scene, t_ray ray)
{
	t_xs_parent	xs_parent;

	xs_parent = xs();
	while (scene)
	{
		xs_parent = mergef_intersections(xs_parent,
				intersect_at(scene->content, ray));
		scene = scene->next;
	}
	return (intersections(xs_parent));
}
