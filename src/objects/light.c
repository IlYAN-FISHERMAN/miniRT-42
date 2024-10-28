/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:26 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:26 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_object	*new_light(t_point3 pos, t_color rgb, double bright)
{
	t_object	*object;

	pos.w = POINT;
	object = galloc(sizeof(t_object));
	if (!object)
		return (0);
	object->data = galloc(sizeof(t_light));
	if (!object->data)
	{
		gfree(object);
		return (0);
	}
	*((t_light *)object->data) = (t_light){.rgb = rgb, .pos = pos,
		.bright = bright, .c_rgb = color_scalar(rgb, bright)};
	object->type = o_light;
	return (object);
}
