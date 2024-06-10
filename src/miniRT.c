#include "miniRT.h"
#include "exit_handler/exit_handler.h"

// Initialize the hooks for the miniRT mlx window
static void	init_hooks(t_minirt *minirt)
{
	mlx_hook(minirt->win, 17, 0, secure_exit, minirt);
}

// Initialize the minirt mlx window
static void	*init_minirt_mlx(t_minirt *minirt)
{
	minirt->mlx = mlx_init();
	if (!minirt->mlx)
		exit(1);
	minirt->win = mlx_new_window(minirt->mlx, 1920, 1080, "miniRT");
	if (!minirt->win)
		crash_exit(minirt);
	init_hooks(minirt);
	return (minirt);
}

t_minirt	*init_minirt(int argc, char **argv)
{
	t_minirt	*minirt;

	(void)argc;
	(void)argv;
	minirt = (t_minirt *)galloc(sizeof(t_minirt));
	if (!minirt)
		exit(1);
	init_minirt_mlx(minirt);
	return (minirt);
}
