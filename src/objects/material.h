/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:44:21 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:44:22 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "objects.h"

typedef t_list			t_mats;

typedef struct s_define
{
	char	*name;
	t_mat	mat;
}	t_define;

typedef struct s_dfmat
{
	t_mat	metal;
	t_mat	platic;
	t_mat	glass;
	t_mat	mirror;
	t_mat	wood;
	t_mat	checkerboard;
	t_mat	bricks;
	t_mat	mat;
}	t_dfmat;

//	mat_metal: Creates a metal material
//	@param color The color of the material
//	@return The material
t_mat	mat_metal(t_color color);

//	mat_plastic: Creates a plastic material
//	@param color The color of the material
//	@return The material
t_mat	mat_plastic(t_color color);

//	mat_glass: Creates a glass material
//	@param color The color of the material
//	@return The material
t_mat	mat_glass(t_color color);

//	mat_mirror: Creates a mirror material
//	@param color The color of the material
//	@return The material
t_mat	mat_mirror(t_color color);

//	mat_wood: Creates a wood material
//	@param color The color of the material
//	@return The material
t_mat	mat_wood(t_color color);

//	mat_checkerboard: Creates a checkerboard material
//	@param color The color of the material
//	@return The material
t_mat	mat_checkerboard(t_color c);

//	mat_bricks: Creates a bricks material
//	@param color The color of the material
//	@return The material
t_mat	mat_bricks(t_color color);

//	mat_mat: Creates a mat material
//	@param color The color of the material
//	@return The material
t_mat	mat_mat(t_color color);

#endif
