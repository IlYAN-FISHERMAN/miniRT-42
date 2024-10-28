/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:50:00 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:50:02 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../miniRT.h"

void	pixelate(t_image *image, t_color color, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i, i <= PREVIEW_PIXEL_SIZE && y + i < image->height)
	{
		j = -1;
		while (++j, j <= PREVIEW_PIXEL_SIZE && x + j < image->width)
			put_pixel_to_image(image, x + j, y + i, color_hex(color));
	}
}

void	fast_render(void)
{
	t_minirt	*minirt;
	int			p[2];
	t_color		color;

	minirt = get_minirt();
	minirt->is_rendering = true;
	p[0] = 0;
	while (p[0] < minirt->size->height)
	{
		p[1] = 0;
		while (p[1] < minirt->size->width)
		{
			color = color_at(ray_for_pixel(minirt->world.cam, p[1], p[0]),
					true, MAX_REFLECT);
			pixelate(minirt->size, color, p[1], p[0]);
			p[1] += PREVIEW_PIXEL_SIZE;
		}
		p[0] += PREVIEW_PIXEL_SIZE;
	}
	display();
}

void	render(void)
{
	t_minirt	*mrt;
	int			p[2];
	int			percent[2];

	mrt = get_minirt();
	mrt->is_rendering = true;
	percent[0] = 0;
	percent[1] = mrt->size->height * mrt->size->width;
	p[0] = -1;
	while (++p[0], p[0] < mrt->size->height)
	{
		p[1] = -1;
		while (++p[1], p[1] < mrt->size->width)
		{
			if (!(++percent[0] % 100000))
				print_percent(ft_itoa((percent[0] * 100) / percent[1]));
			put_pixel_to_image(mrt->size, p[1], p[0], color_hex(
					color_at(ray_for_pixel(mrt->world.cam, p[1], p[0]),
						false, MAX_REFLECT)));
		}
	}
	display();
}
