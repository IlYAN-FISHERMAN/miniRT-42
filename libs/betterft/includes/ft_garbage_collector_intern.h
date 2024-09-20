/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector_intern.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:04:22 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 18:05:36 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR_INTERN_H
# define FT_GARBAGE_COLLECTOR_INTERN_H

# include "betterft.h"

// t_garbcol: A garbage collector node
typedef struct s_garbcol
{
	void				*content;
	struct s_garbcol	*next;
}					t_garbcol;

//	getgarbage: Get the garbage collector list
//	@return The garbage collector list
t_garbcol	**getgarbage(void);

#endif