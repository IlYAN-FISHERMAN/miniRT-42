/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:29 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:30 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "objects.h"

typedef struct s_amb
{
	double	light;
	t_color	rgb;
	t_color	c_rgb;
}	t_amb;

typedef struct s_light
{
	t_point3	pos;
	t_color		rgb;
	double		bright;
	t_color		c_rgb;
}	t_light;

//  new_light: Create a new light object
//  @param pos The position of the light
//	@param rgb The color of the light
//	@param bright The brightness of the light
//  @return A new light object
t_object		*new_light(t_point3 pos, t_color rgb, double bright);

#endif
