/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:54:07 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:54:08 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector3	vreflect(t_vector3 v, t_vector3 normal)
{
	return (vsub(v, vmul(normal, 2 * vdot(v, normal))));
}
