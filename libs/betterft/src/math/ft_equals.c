/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:32:35 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:36:08 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

bool	ft_equalsf(float a, float b)
{
	float		diff;

	diff = a - b;
	if (diff < 0)
		diff = -diff;
	return (diff < EPSILONF);
}

bool	ft_equalsd(double a, double b)
{
	double			diff;

	diff = a - b;
	if (diff < 0)
		diff = -diff;
	return (diff < EPSILOND);
}
