/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:42:41 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:42:43 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	ft_atof(char *str)
{
	double	nb;
	int		i;
	double	j;
	double	sign;

	i = -1;
	nb = 0;
	j = 0;
	sign = 1;
	if (str[0] == '-' && !++i)
		sign = -1;
	while (str[++i])
	{
		if (str[i] == '.')
		{
			while (str[++i] && ++j)
				nb = (nb * (double)pow(10, j) + (str[i] - 48)) / pow(10, j);
			return (nb * sign);
		}
		nb = nb * 10 + (str[i] - 48);
	}
	return (nb * sign);
}

int	ft_atof_xyz(double *x, double *y, double *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atof(str[0]);
	*y = ft_atof(str[1]);
	*z = ft_atof(str[2]);
	ft_free_tab(str);
	return (1);
}

int	ft_atoi_xyz(int *x, int *y, int *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atoi(str[0]);
	*y = ft_atoi(str[1]);
	*z = ft_atoi(str[2]);
	ft_free_tab(str);
	return (1);
}

int	ft_atoi_rgb(unsigned char *x, unsigned char *y,
				unsigned char *z, char **str)
{
	if (!str)
		return (0);
	*x = ft_atoi(str[0]);
	*y = ft_atoi(str[1]);
	*z = ft_atoi(str[2]);
	ft_free_tab(str);
	return (1);
}
