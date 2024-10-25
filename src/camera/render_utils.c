#include "render.h"
#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

static void	print_box(int size_x, int size_y)
{
	t_minirt	*minirt;
	void		*img;
	int			x_pos;
	int			y_pos;

	minirt = get_minirt();
	x_pos = minirt->size->width / 2 - size_x / 2 + 10;
	y_pos = minirt->size->height / 2 - size_y / 2;
	img = mlx_new_image(minirt->win.mlx, size_x, size_y);
	mlx_put_image_to_window(minirt->win.mlx, minirt->win.windo, img,
		x_pos - 10, y_pos - 20);
	mlx_destroy_image(minirt->win.mlx, img);
}

void	print_message(char *msg)
{
	t_minirt	*minirt;
	size_t		len;
	int			y_pos;
	int			x_pos;

	len = ft_strlen(msg);
	minirt = get_minirt();
	y_pos = minirt->size->height * 0.5 - 15;
	x_pos = minirt->size->width * 0.5 - len * 3;
	print_box(len * 8, 30);
	mlx_string_put(minirt->win.mlx,
		minirt->win.windo, x_pos, y_pos, 0xFFFFFF, msg);
	mlx_do_sync(minirt->win.mlx);
}

void	print_percent(char *info)
{
	t_minirt	*minirt;
	int			y_pos;
	int			x_pos;

	minirt = get_minirt();
	if (!info)
		crash_exit(minirt, (char *[]){"miniRT", "render", 0},
			"Malloc failed");
	y_pos = minirt->size->height * 0.5 - 15;
	x_pos = minirt->size->width * 0.5 - 50;
	print_box(120, 30);
	mlx_string_put(minirt->win.mlx, minirt->win.windo, x_pos, y_pos, 0xFFFFFF,
		"Rendering...");
	mlx_string_put(minirt->win.mlx, minirt->win.windo,
		x_pos + 80, y_pos, 0xFFFFFF, info);
	mlx_string_put(minirt->win.mlx, minirt->win.windo,
		x_pos + 95, y_pos, 0xFFFFFF, "%");
	gfree(info);
	mlx_do_sync(minirt->win.mlx);
}

void	display(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	mlx_put_image_to_window(minirt->win.mlx, minirt->win.windo,
		minirt->size->mlx_img, 0, 0);
	if (minirt->is_first < 2)
	{
		print_message("Enter to render");
		minirt->is_first++;
	}
	minirt->is_rendering = false;
}

void	put_pixel_to_image(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width
		|| y < 0 || y >= image->height)
		return ;
	color = mlx_get_color_value(image->mlx, color);
	*(int *)(image->data + (y * image->size_line + x * image->bppd)) = color;
}
