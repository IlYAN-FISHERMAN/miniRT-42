#include "exit_handler.h"

int	secure_exit(t_minirt *minirt)
{
	if (minirt->mlx)
		mlx_destroy_window(minirt->mlx, minirt->win);
	gfree(minirt);
	cleargarbage();
	exit(0);
}

int	crash_exit(void *data)
{
	t_minirt	*minirt;

	perror(C_RED"miniRT error"C_RESET);
	minirt = (t_minirt *)data;
	if (minirt->mlx && minirt->win)
		mlx_destroy_window(minirt->mlx, minirt->win);
	if (minirt->mlx)
		gfree(minirt->mlx);
	gfree(minirt);
	cleargarbage();
	exit(0);
}
