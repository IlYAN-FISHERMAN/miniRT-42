#include "exit_handler.h"

void	free_object(void *object)
{
	gfree(((t_object *)object)->data);
	gfree(object);
}

static void	clear_materials(t_minirt *minirt)
{
	if (minirt->df_mat.bricks.bumpmap)
	{
		gfree(minirt->df_mat.bricks.bumpmap->data);
		gfree(minirt->df_mat.bricks.bumpmap);
	}
	if (minirt->df_mat.wood.bumpmap)
	{
		gfree(minirt->df_mat.wood.bumpmap->data);
		gfree(minirt->df_mat.wood.bumpmap);
	}
}

void	clear_memory(t_minirt *minirt)
{
	if (minirt->mat)
		ft_lstclear(&minirt->mat, &free_mat);
	if (minirt->size)
	{
		if (minirt->size->mlx_img)
			mlx_destroy_image(minirt->win.mlx, minirt->size->mlx_img);
		gfree(minirt->size);
	}
	if (minirt->win.mlx && minirt->win.windo)
		mlx_destroy_window(minirt->win.mlx, minirt->win.windo);
	if (minirt->win.mlx)
		mlx_destroy_display(minirt->win.mlx);
	if (minirt->win.mlx)
		gfree(minirt->win.mlx);
	if (minirt->world.amb)
		gfree(minirt->world.amb);
	if (minirt->world.cam)
		gfree(minirt->world.cam);
	if (minirt->world.scene)
		ft_lstclear(&minirt->world.scene, &free_object);
	if (minirt->world.lights)
		ft_lstclear(&minirt->world.lights, &free_object);
	if (minirt->threads)
		gfree(minirt->threads);
	clear_materials(minirt);
}

int	secure_exit(void *data)
{
	t_minirt	*minirt;

	minirt = data;
	clear_memory(minirt);
	cleargarbage();
	exit(0);
}

int	crash_exit(t_minirt *minirt, char **context, char *msg)
{
	printf("Error\n");
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
