/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:49:39 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:49:40 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_image	*new_image(int width, int height)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (!image)
		return (0);
	image->width = width;
	image->height = height;
	return (image);
}
