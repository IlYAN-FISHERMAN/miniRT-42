/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:11:10 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/16 21:54:57 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

// includes
# include "betterft_includes.h"
# include "ft_garbage_collector.h"

//	ft_bzero: Writes 'n' zeroed bytes to the string 's'.
//	@param 's': The string to write to.
//	@param 'n': The number of bytes to write.
void		ft_bzero(void *s, size_t n);

//	ft_calloc: Allocates memory for an array of 'count' elements of 'size' bytes
//	each and returns a pointer to the allocated memory.
//	The memory is set to zero.
//	@param 'count': The number of elements to allocate.
//	@param 'size': The size of each element.
//	@return The allocated memory.
void		*ft_calloc(size_t count, size_t size);

//	ft_memchr: Locates the first occurrence of 'c' (converted to an unsigned char)
//	in the initial 'n' bytes of the string 's'.
//	@param 's': The string to search in.
//	@param 'c': The character to search for.
//	@param 'n': The number of bytes to search.
//	@return A pointer to the located byte or NULL if the byte does not occur.
void		*ft_memchr(const void *s, int c, size_t n);

//	ft_memcmp: Compares the first 'n' bytes of the memory areas 's1' and 's2'.
//	@param 's1': The first memory area to compare.
//	@param 's2': The second memory area to compare.
//	@param 'n': The number of bytes to compare.
//	@return An integer less than, equal to, or greater than zero if the first
int			ft_memcmp(const void *s1, const void *s2, size_t n);

//	ft_memcpy: Copies 'n' bytes from memory area 'src' to memory area 'dest'.
//	The memory areas must not overlap.
//	@param 'dest': The destination memory area.
//	@param 'src': The source memory area.
//	@param 'n': The number of bytes to copy.
//	@return The original value of 'dest'.
void		*ft_memcpy(void *dest, const void *src, size_t n);

//	ft_memmove: Copies 'n' bytes from memory area 'src' to memory area 'dest'.
//	The memory areas may overlap.
//	@param 'dest': The destination memory area.
//	@param 'src': The source memory area.
//	@param 'n': The number of bytes to copy.
//	@return The original value of 'dest'.
void		*ft_memmove(void *dest, const void *src, size_t n);

//	ft_memset: Writes 'n' bytes of value 'c' (converted to an unsigned char) to
//	the string 's'.
//	@param 's': The string to write to.
//	@param 'c': The character to write.
//	@param 'n': The number of bytes to write.
//	@return The original value of 's'.
void		*ft_memset(void *s, int c, size_t n);

//	ft_memsuperclear: Frees the memory pointed to by 'm' as an array of 'size'
//	bytes.
//	@param 'm': The super pointer to the memory to free.
//	@param 'size': The size of a single element in the array.
void		ft_memsuperclear(void **m, size_t size);

//	ft_reallocf: Reallocates the memory block pointed to by 'ptr' to 'newsize'
//	bytes, freeing the original memory block.
//	@param 'ptr': The pointer to the memory block to reallocate.
//	@param 'size': The size of the original memory block.
//	@param 'newsize': The new size of the memory block.
//	@return The new memory block or NULL if the allocation fails.
void		*ft_reallocf(void *ptr, size_t size, size_t newsize);

//	ft_memncat: Appends 'nb' bytes from the memory area 'src' to the memory area
//	'dest' starting at the 'start' byte.
//	@param 'dest': The destination memory area.
//	@param 'start': The starting byte in 'dest'.
//	@param 'src': The source memory area.
//	@param 'nb': The number of bytes to append.
//	@return The destination memory area.
void		*ft_memncat(void *dest, size_t start, void *src, size_t nb);

//	ft_memtostr: Converts the memory area 'mem' of 'size' bytes to a string.
//	@param 'mem': The memory area to convert.
//	@param 'size': The size of the memory area.
//	@return The new string or NULL if the allocation fails.
char		*ft_memtostr(void *mem, size_t size);

//	ft_swap: Swaps the values of 'a' and 'b'.
//	@param 'a': The first value.
//	@param 'b': The second value.
void		ft_swap(void *a, void *b);

#endif