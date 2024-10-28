/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:57 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:53:57 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_tuple4	vadd(t_tuple4 v, t_tuple4 u)
{
	return ((t_tuple4){v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w});
}

t_tuple4	vsub(t_tuple4 v, t_tuple4 u)
{
	return ((t_tuple4){v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w});
}

t_tuple4	vneg(t_tuple4 v)
{
	return ((t_tuple4){-v.x, -v.y, -v.z, -v.w});
}

t_tuple4	vmul(t_tuple4 v, double scalar)
{
	return ((t_tuple4){v.x * scalar, v.y * scalar, v.z * scalar, v.w});
}

t_tuple4	vdiv(t_tuple4 v, double scalar)
{
	return ((t_tuple4){v.x / scalar, v.y / scalar, v.z / scalar, v.w});
}
