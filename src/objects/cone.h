/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:16 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:16 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "objects.h"
# include "cylinder.h"

typedef struct s_cone
{
	t_vector3	origin;
	t_vector3	normal;
	double		radius;
	double		height;
	t_color		rgb;
}	t_cone;

typedef struct s_calc_cone
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		disc_sqrt;
	double		height;
	bool		does_inter[2];
	double		t[2];
	double		y[2];
}	t_calc_cone;

//  new_cone: Create a new cone object
//  @param origin The origin of the cone
//  @param radius The radius of the cone
//	@param height The height of the cone
//	@param normal The normal of the cone
//	@param color The color of the cone
//	@note The cone implementation does not follows the book
//	implementation. If errors are found, refer to the book
//  @return A new cone object
t_object		*new_cone(t_point3 origin, double *rad_hei,
					t_vector3 normal, t_color color);

//  uv_mapping_cone: Map a point on the cone to a 2D UV coordinate
//  @param local_point The point on the cone
//  @param is_caps True if the point is on the caps, false otherwise
//  @return The UV coordinate
t_vector2		uv_mapping_cone(t_point3 local_point, bool is_caps);

#endif
