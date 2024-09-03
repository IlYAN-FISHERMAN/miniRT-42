#include "exit_handler.h"

int	secure_exit(void *data)
{
	t_minirt	*minirt;

	minirt = data;
	if (minirt && minirt->win.mlx)
		mlx_destroy_window(minirt->win.mlx, minirt->win.windo);
	cleargarbage();
	exit(1);
}

void	clear_memory(t_minirt *minirt)
{
	t_scene		*tmp;

	tmp = minirt->scene;
	if (minirt && minirt->win.mlx)
		mlx_destroy_window(minirt->win.mlx, minirt->win.windo);
	if (minirt->size)
		gfree(minirt->size);
	if (minirt->amb)
		gfree(minirt->amb);
	if (minirt->cam)
		gfree(minirt->cam);
	while (tmp)
	{
		if (tmp->content)
			gfree(tmp->content);
		tmp = tmp->next;
	}
	if (minirt->scene)
		ft_lstclear(&minirt->scene, &gfree);
}

int	crash_exit(t_minirt *minirt, char **context, char *msg)
{
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
	clear_memory(minirt);
	cleargarbage();
	exit(1);
}
