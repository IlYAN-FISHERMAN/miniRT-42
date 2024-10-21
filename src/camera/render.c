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
			put_pixel_to_image(image->mlx_img, x + j, y + i, color_hex(color));
	}
}

void	put_pixel_to_image(void *img, int x, int y, int color)
{
	static char	*data;
	static int	bpp;
	static int	size_line;
	static int	endian;
	static int	bppd;

	if (!data)
	{
		data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
		bppd = bpp >> 3;
	}
	if (x < 0 || x >= get_minirt()->size->width
		|| y < 0 || y >= get_minirt()->size->height)
		return ;
	color = mlx_get_color_value(get_minirt()->win.mlx, color);
	*(int *)(data + (y * size_line + x * bppd)) = color;
}

void	display(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	mlx_put_image_to_window(minirt->win.mlx, minirt->win.windo,
		minirt->size->mlx_img, 0, 0);
	mlx_do_sync(minirt->win.mlx);
	minirt->is_rendering = false;
}

void	fast_render(void)
{
	t_minirt	*minirt;
	int			x;
	int			y;
	t_color		color;

	minirt = get_minirt();
	minirt->is_rendering = true;
	minirt->world.amb->c_rgb
		= color_scalar(minirt->world.amb->rgb, minirt->world.amb->light);
	minirt->world.amb->is_calc = true;
	y = 0;
	while (++y, y < minirt->size->height)
	{
		x = 0;
		while (++x, x < minirt->size->width)
		{
			color = color_at(ray_for_pixel(minirt->world.cam, x, y),
					true, MAX_REFLECT);
			pixelate(minirt->size, color, x, y);
			x += PREVIEW_PIXEL_SIZE;
		}
		y += PREVIEW_PIXEL_SIZE;
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
	mrt->world.amb->c_rgb
		= color_scalar(mrt->world.amb->rgb, mrt->world.amb->light);
	mrt->world.amb->is_calc = true;
	p[0] = -1;
	while (++p[0], p[0] < mrt->size->height)
	{
		p[1] = -1;
		while (++p[1], p[1] < mrt->size->width)
		{
			if (!(++percent[0] % 100000))
				print_percent(ft_itoa((percent[0] * 100) / percent[1]));
			put_pixel_to_image(mrt->size->mlx_img, p[1], p[0], color_hex(
					color_at(ray_for_pixel(mrt->world.cam, p[1], p[0]),
						false, MAX_REFLECT)));
		}
	}
	display();
}
