#include "render.h"
#include "../miniRT.h"

void	pixelate(t_image *image, t_color color, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i, i <= 5 && y + i < image->height)
	{
		j = -1;
		while (++j, j <= 5 && x + j < image->width)
			image->data[y + i][x + j] = color_hex(color);
	}
}

void	put_pixel_to_image(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		bppd;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	bppd = bpp >> 3;
	*(int *)(data + (y * size_line + x * bppd)) = color;
}

void	display(void)
{
	t_minirt	*minirt;
	void		*img;
	int			i;
	int			j;

	minirt = get_minirt();
	img = mlx_new_image(minirt->win.mlx,
			minirt->size->width, minirt->size->height);
	i = -1;
	while (++i < minirt->size->height)
	{
		j = -1;
		while (++j < minirt->size->width)
			put_pixel_to_image(img, j, i, minirt->size->data[i][j]);
	}
	mlx_put_image_to_window(minirt->win.mlx, minirt->win.windo, img, 0, 0);
	mlx_destroy_image(minirt->win.mlx, img);
}

void	fast_render(void)
{
	t_minirt	*minirt;
	int			x;
	int			y;
	t_color		color;

	minirt = get_minirt();
	minirt->amb->c_rgb = color_scalar(minirt->amb->rgb, minirt->amb->light);
	minirt->amb->is_calc = true;
	y = 0;
	while (++y, y < minirt->size->height)
	{
		x = 0;
		while (++x, x < minirt->size->width)
		{
			color = color_at(minirt->scene, minirt->amb,
					ray_for_pixel(minirt->cam, x, y), true);
			pixelate(minirt->size, color, x, y);
			x += 5;
		}
		y += 5;
	}
	display();
}

void	render(void)
{
	t_minirt	*minirt;
	int			x;
	int			y;
	int			percent[2];

	minirt = get_minirt();
	percent[0] = 0;
	percent[1] = minirt->size->height * minirt->size->width;
	minirt->amb->c_rgb = color_scalar(minirt->amb->rgb, minirt->amb->light);
	minirt->amb->is_calc = true;
	y = -1;
	while (++y, y < minirt->size->height)
	{
		x = -1;
		while (++x, x < minirt->size->width)
		{
			percent[0]++;
			if (!(percent[0] % 100000))
				print_percent(ft_itoa((percent[0] * 100) / percent[1]));
			minirt->size->data[y][x] = color_hex(color_at(minirt->scene,
						minirt->amb, ray_for_pixel(minirt->cam, x, y), false));
		}
	}
	display();
}
