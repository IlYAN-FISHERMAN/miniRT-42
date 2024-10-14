#include "render.h"
#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

static void	print_box(int x_pos, int y_pos)
{
	t_minirt	*minirt;
	void		*img;

	minirt = get_minirt();
	img = mlx_new_image(minirt->win.mlx, 120, 30);
	mlx_put_image_to_window(minirt->win.mlx, minirt->win.windo, img,
		x_pos - 10, y_pos - 20);
	mlx_destroy_image(minirt->win.mlx, img);
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
	print_box(x_pos, y_pos);
	mlx_string_put(minirt->win.mlx, minirt->win.windo, x_pos, y_pos, 0xFFFFFF,
		"Rendering...");
	mlx_string_put(minirt->win.mlx, minirt->win.windo,
		x_pos + 80, y_pos, 0xFFFFFF, info);
	mlx_string_put(minirt->win.mlx, minirt->win.windo,
		x_pos + 95, y_pos, 0xFFFFFF, "%");
	gfree(info);
}
