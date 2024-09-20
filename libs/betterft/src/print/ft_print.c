/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:34:49 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:39:00 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*(s++))
		ft_putchar_fd(*(s - 1), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_base(n, "0123456789", fd);
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
