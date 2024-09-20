/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:14:38 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:10:15 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

// includes
# include "ft_printf.h"

//	ft_putchar_fd: Writes the character 'c' to the file descriptor 'fd'.
//	@param 'c': The character to write.
//	@param 'fd': The file descriptor to write to.
void		ft_putchar_fd(char c, int fd);

//	ft_putendl_fd: Writes the string 's' to the file descriptor 'fd' followed by
//	a newline.
//	@param 's': The string to write.
//	@param 'fd': The file descriptor to write to.
void		ft_putendl_fd(char *s, int fd);

//	ft_putnbr_base: Writes the integer 'n' to the file descriptor 'fd' in the
//	given base.
//	@param 'n': The integer to write.
//	@param 'base': The base to use for the conversion.
//	@param 'fd': The file descriptor to write to.
void		ft_putnbr_base(int n, char *base, int fd);

//	ft_putnbr_fd: Writes the integer 'n' to the file descriptor 'fd'.
//	@param 'n': The integer to write.
//	@param 'fd': The file descriptor to write to.
void		ft_putnbr_fd(int n, int fd);

//	ft_putstr_fd: Writes the string 's' to the file descriptor 'fd'.
//	@param 's': The string to write.
//	@param 'fd': The file descriptor to write to.
void		ft_putstr_fd(char *s, int fd);

#endif