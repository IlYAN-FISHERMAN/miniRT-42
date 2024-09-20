/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_intern.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:26:21 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:10:45 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_INTERN_H
# define FT_GET_NEXT_LINE_INTERN_H

# include "betterft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_gnl
{
	char		buffer[BUFFER_SIZE];
	ssize_t		size;
	int			fd;
	char		*line;
}				t_gnl;

#endif