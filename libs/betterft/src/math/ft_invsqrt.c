/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invsqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:57:46 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/08 10:05:45 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_invsqrt(float n)
{
	float	half_n;
	int		i;
	float	x;

	half_n = n * 0.5f;
	i = *(int *)&n;
	i = 0x5f3759df - (i >> 1);
	x = *(float *)&i;
	x = x * (1.5f - (half_n * x * x));
	return (x);
}

float	ft_invsqrt_iter(float n, int iter)
{
	float	half_n;
	int		i;
	float	x;

	half_n = n * 0.5f;
	i = *(int *)&n;
	i = 0x5f3759df - (i >> 1);
	x = *(float *)&i;
	while (iter--)
		x = x * (1.5f - (half_n * x * x));
	return (x);
}
