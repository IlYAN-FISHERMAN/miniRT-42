#include "exit_handler.h"
#include "ft_garbage_collector.h"
#include "ft_linked_list.h"

int	secure_exit(void *data)
{
	t_minirt	*minirt;

	minirt = data;
	clear_memory(minirt);
	cleargarbage();
	exit(0);
}

void	free_object(void *object)
{
	gfree(((t_object *)object)->data);
	gfree(object);
}

//	since clear_image wasn't working properly on mac, we decided to
//	let exit function handle it (lol)
static void	clear_image(t_minirt *minirt, t_image *image)
{
	(void)minirt;
	(void)image;
}

void	clear_memory(t_minirt *minirt)
{
	if (minirt && minirt->mat)
		ft_lstclear(&minirt->mat, &free_mat);
	if (minirt && minirt->size)
		clear_image(minirt, minirt->size);
	if (minirt && minirt->win.mlx && minirt->win.windo)
		mlx_destroy_window(minirt->win.mlx, minirt->win.windo);
	if (minirt && minirt->win.mlx)
		gfree(minirt->win.mlx);
	if (minirt && minirt->world.amb)
		gfree(minirt->world.amb);
	if (minirt && minirt->world.cam)
		gfree(minirt->world.cam);
	if (minirt && minirt->world.scene)
		ft_lstclear(&minirt->world.scene, &free_object);
	if (minirt && minirt->world.lights)
		ft_lstclear(&minirt->world.lights, &free_object);
	if (minirt && minirt->threads)
		gfree(minirt->threads);
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
