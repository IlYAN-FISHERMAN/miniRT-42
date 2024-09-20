#include "miniRT.h"
#include "camera/image.h"
#include "exit_handler/exit_handler.h"
#include "parsing/parsing.h"

static void	init_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->win.windo, 17, 0, secure_exit, minirt);
}

void	*init_minirt_mlx(t_minirt *minirt)
{
	minirt->win.mlx = mlx_init();
	if (!minirt->win.mlx)
		crash_exit(minirt, NULL, "mlx failed");
	minirt->win.windo = \
		mlx_new_window(minirt->win.mlx, minirt->size->width,
			minirt->size->height, "miniRT");
	if (!minirt->win.windo)
		crash_exit(minirt, NULL, "windo malloc fail");
	init_hooks(minirt);
	return (minirt);
}

t_minirt	*init_minirt(t_minirt *minirt, int argc, char **argv)
{
	check_error(argc, argv, minirt);
	pars_map(argv, &minirt);
	if (DEBUG)
		print_token(minirt, minirt->scene);
	return (minirt);
}
