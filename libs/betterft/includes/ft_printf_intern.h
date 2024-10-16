/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_intern.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:08:36 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:15:41 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERN_H
# define FT_PRINTF_INTERN_H

# include "betterft.h"

//	Converts an integer to a hexadecimal string
void	ft_inttohex(unsigned long int n, int *size);
//	Prints a character and increments the size counter
void	ft_putchar_count(char c, int *size);
//	Prints a string and increments the size counter
void	ft_putstr_count(char *s, int *size);
//	Prints a number in a given base and increments the size counter
void	ft_putnbr_count(int n, char *base, int *size);
//	Prints a unsigned long int in a given base and increments the size counter
void	ft_putunnbr_count(unsigned long int n, char *base, int *size);

#endif