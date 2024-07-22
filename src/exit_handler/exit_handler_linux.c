#include "exit_handler.h"

int	secure_exit(void *data)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)data;
	if (minirt->win.mlx && minirt->win.windo)
		mlx_destroy_window(minirt->win.mlx, minirt->win.windo);
	if (minirt->win.mlx)
		mlx_destroy_display(minirt->win.mlx);
	if (minirt->win.mlx)
		gfree(minirt->win.mlx);
	gfree(minirt);
	cleargarbage();
	exit(0);
}

int	crash_exit(void *data, char **context, char *msg)
{
	(void)data;
	while (context && *context)
	{
		ft_putstr_fd(*context, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		if (!context[1] && !ft_strcmp(*context, "warning"))
			ft_putstr_fd(C_YELLOW, STDERR_FILENO);
		else if (!context[1])
			ft_putstr_fd(C_RED, STDERR_FILENO);
		context++;
	}
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_putstr_fd(C_RESET, STDERR_FILENO);
	cleargarbage();
	exit(1);
}
