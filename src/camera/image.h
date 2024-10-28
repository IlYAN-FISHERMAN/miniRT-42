/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:49:41 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:49:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "camera.h"
# include "../objects/shape.h"

typedef struct s_image
{
	int		width;
	int		height;
	void	*mlx_img;
	void	*mlx;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		bppd;
	bool	exist;
}	t_image;

typedef struct s_size
{
	int	height;
	int	width;
}	t_size;

//	new_image: Create a new image
//  @param width The width of the image
//  @param height The height of the image
//  @return A new allocated image
t_image	*new_image(int width, int height);

#endif
