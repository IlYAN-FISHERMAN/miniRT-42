#include "camera.h"
#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

void	print_percent(char *info)
{
	t_minirt	*minirt;
	int			y_pos;
	int			x_pos;

	minirt = get_minirt();
	if (!info)
		crash_exit(minirt, (char *[]){"miniRT", "render", 0},
			"Malloc failed");
	y_pos = minirt->size->height / 2 - 15;
	x_pos = minirt->size->width / 2 - 50;
	mlx_clear_window(minirt->win.mlx, minirt->win.windo);
	mlx_string_put(minirt->win.mlx, minirt->win.windo, x_pos, y_pos, 0xFFFFFF,
		"Rendering...");
	mlx_string_put(minirt->win.mlx, minirt->win.windo,
		x_pos + 80, y_pos, 0xFFFFFF, info);
	mlx_string_put(minirt->win.mlx, minirt->win.windo,
		x_pos + 95, y_pos, 0xFFFFFF, "%");
	gfree(info);
}
