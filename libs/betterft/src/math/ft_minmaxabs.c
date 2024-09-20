/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmaxabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:57:05 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:32:29 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_absol(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_min(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

int	ft_max(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}
