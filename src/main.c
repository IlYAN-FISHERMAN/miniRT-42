#include "miniRT.h"

static void	put_pixel_to_image(void *img, int x, int y, int color)
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

int	main(int argc, char **argv)
{
	t_minirt	minirt;
	void		*img;
	int			i;
	int			j;

	ft_bzero(&minirt, sizeof(minirt));
	init_minirt(&minirt, argc, argv);
	init_minirt_mlx(&minirt);
	render();
	img = mlx_new_image(minirt.win.mlx,
			minirt.size->width, minirt.size->height);
	i = -1;
	while (++i < minirt.size->height)
	{
		j = -1;
		while (++j < minirt.size->width)
			put_pixel_to_image(img, j, i, minirt.size->data[i][j]);
	}
	mlx_put_image_to_window(minirt.win.mlx, minirt.win.windo, img, 0, 0);
	mlx_loop(minirt.win.mlx);
	exit(0);
}
