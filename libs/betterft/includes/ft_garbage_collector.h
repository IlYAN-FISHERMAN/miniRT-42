/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:48:50 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 16:59:51 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_COLLECTOR_H
# define FT_GARBAGE_COLLECTOR_H

//	includes
# include "betterft_includes.h"

# ifndef GARBAGE_COLLECTOR
// GARBAGE_COLLECTOR: A flag to enable or disable the garbage collector
// Default: enabled
#  define GARBAGE_COLLECTOR 1
# endif

//	gfree: Free the memory at the specified 'address' and remove it from the
//	garbage collector. If the address is not found in the garbage collector,
//	the function will free the memory directly.
//	It is recommended to use this function instead of `free` using this library.
//	@param address The address to free
void		gfree(void *address);

//	addgarbage: Add the memory at the specified 'address' to the garbage
//	collector
//	@param address The address to add
//	@return The address itself
void		*addgarbage(void *address);

//	galloc: Returns a new allocation of 'size' bytes from the garbage collector
//	@param size The size of the allocation
//	@return The new allocation
void		*galloc(size_t size);

//	cleargarbage: Free all memory allocated in the garbage collector and clear
//	the collector itself
void		cleargarbage(void);

#endif