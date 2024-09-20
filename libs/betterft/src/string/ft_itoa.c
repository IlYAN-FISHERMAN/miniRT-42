/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:04:38 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:41:41 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static unsigned int	inputparser(int n)
{
	unsigned int	output;

	if (n < 0)
		output = -n;
	else
		output = n;
	return (output);
}

char	*ft_itoa_base_un(unsigned long n, const char *base)
{
	char				*p;
	unsigned long int	temp;
	size_t				len;

	temp = n;
	len = 0;
	while (++len, temp >= ft_strlen(base))
		temp /= ft_strlen(base);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	temp = n;
	while (len-- > 0)
	{
		p[len] = base[temp % ft_strlen(base)];
		temp /= ft_strlen(base);
	}
	return (p);
}

char	*ft_itoa_un(unsigned long n)
{
	char			*p;
	unsigned int	temp;
	int				len;

	temp = n;
	len = 0;
	while (++len, temp >= 10)
		temp /= 10;
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	temp = n;
	while (len-- > 0)
	{
		p[len] = (temp % 10) + '0';
		temp /= 10;
	}
	return (p);
}

char	*ft_itoa_base(int n, const char *base)
{
	char			*p;
	unsigned int	temp;
	int				isneg;
	int				len;

	isneg = 0;
	if (n < 0)
		isneg = 1;
	temp = inputparser(n);
	len = 0;
	while (++len, temp >= ft_strlen(base))
		temp /= ft_strlen(base);
	p = (char *)ft_calloc(len + 1 + isneg, sizeof(char));
	if (!p)
		return (0);
	temp = inputparser(n);
	while (len-- > 0)
	{
		p[len + isneg] = base[temp % ft_strlen(base)];
		temp /= ft_strlen(base);
	}
	if (isneg)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, "0123456789"));
}
