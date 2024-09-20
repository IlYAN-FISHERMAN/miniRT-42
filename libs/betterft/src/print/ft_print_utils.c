/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:33:19 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:34:20 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_base(int n, char *base, int fd)
{
	unsigned int	un;
	size_t			baselen;

	un = n;
	if (n < 0)
		un = -n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	baselen = ft_strlen(base);
	if (un < baselen)
		ft_putchar_fd(base[un], fd);
	else if (un > baselen)
	{
		ft_putnbr_base(un / baselen, base, fd);
		ft_putnbr_base(un % baselen, base, fd);
	}
}
