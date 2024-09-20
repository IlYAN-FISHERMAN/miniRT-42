/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:07:30 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:10:59 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

//	ft_get_next_line: Reads a line from the file descriptor 'fd' and returns
//	it as a dynamically allocated string.
//	Returns NULL at the end of the file or if an error occurs.
char		*ft_get_next_line(int fd);

#endif