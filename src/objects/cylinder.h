/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:52:22 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:23 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "objects.h"

typedef struct s_cylin
{
	t_vector3	origin;
	t_vector3	normal;
	double		radius;
	double		height;
	t_color		rgb;
}	t_cylin;

typedef struct s_calc_cylin
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		disc_sqrt;
	double		half_h;
	bool		does_inter[2];
	double		t[2];
	double		y[2];
}	t_calc_cylin;

//  new_cylinder: Create a new cylinder object
//  @param origin The origin of the cylinder
//  @param radius The radius of the cylinder
//	@param height The height of the cylinder
//	@param normal The normal of the cylinder
//  @return A new cylinder object
t_object		*new_cylinder(t_point3 origin, double *rad_hei,
					t_vector3 normal, t_color color);

#endif
