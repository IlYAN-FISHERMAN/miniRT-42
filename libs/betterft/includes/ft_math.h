/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:26:11 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/12 18:08:35 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

// includes
# include "betterft_includes.h"

// defines
# define PI 3.14159265358979323846
# define DEG2RADF 0.017453292519943295f
# define RAD2DEGF 57.29577951308232f
# define EPSILONF 0.00001f
# define EPSILOND 0.0000000001

//	ft_invsqrt: Returns the inverse square root of 'n'.
//	@param n: The number to calculate the inverse square root.
//	@return: The inverse square root of 'n'.
float	ft_invsqrt(float n);

//	ft_invsqrt_iter: Returns the inverse square root of 'n' after 'iter'
//	iterations.
//	@param n: The number to calculate the inverse square root.
//	@param iter: The number of iterations to perform.
//	@return: The inverse square root of 'n'.
float	ft_invsqrt_iter(float n, int iter);

//	ft_absol: Returns the absolute value of 'nb'.
//	@param nb: The number to calculate the absolute value.
//	@return: The absolute value of 'nb'.
int		ft_absol(int nb);

//	ft_min: Returns the minimum value between 'nb1' and 'nb2'.
//	@param nb1: The first number to compare.
//	@param nb2: The second number to compare.
//	@return: The minimum value between 'nb1' and 'nb2'.
int		ft_min(int nb1, int nb2);

//	ft_max: Returns the maximum value between 'nb1' and 'nb2'.
//	@param nb1: The first number to compare.
//	@param nb2: The second number to compare.
//	@return: The maximum value between 'nb1' and 'nb2'.
int		ft_max(int nb1, int nb2);

//	ft_equalsf: Returns true if 'a' and 'b' are equal, false otherwise.
//	@param a: The first number to compare.
//	@param b: The second number to compare.
//	@return: true if 'a' and 'b' are equal, false otherwise.
bool	ft_equalsf(float a, float b);

//	ft_equalsd: Returns true if 'a' and 'b' are equal, false otherwise.
//	@param a: The first number to compare.
//	@param b: The second number to compare.
//	@return: true if 'a' and 'b' are equal, false otherwise.
bool	ft_equalsd(double a, double b);

#endif