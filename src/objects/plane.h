/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:09 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:53:09 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "objects.h"

typedef struct s_plane
{
	t_point3		origin;
	t_vector3		normal;
	t_color			color;
}	t_plane;

//  new_plane: Create a new plane object
//  @param origin The origin of the plane
//  @param normal The normal of the plane
//  @return A new plane object
t_object	*new_plane(t_point3 origin, t_vector3 normal, t_color color);

#endif