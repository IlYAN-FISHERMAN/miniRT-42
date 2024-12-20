/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:32:00 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:32:01 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "camera/image.h"
#include "exit_handler/exit_handler.h"
#include "parsing/parsing.h"

static int	handle_key(int key, t_minirt *minirt)
{
	if (DEBUG)
		printf("Key: %d\n", key);
	if (key == KEY_ESC)
		secure_exit(minirt);
	else if (!minirt->update && (key == KEY_D || key == KEY_A || key == KEY_W
			|| key == KEY_S || key == KEY_LEFT || key == KEY_UP
			|| key == KEY_RIGHT || key == KEY_DOWN || key == KEY_SPACE
			|| key == KEY_X || key == KEY_R))
	{
		camera_move(key);
		minirt->update = true;
	}
	else if (key == KEY_ENTER)
	{
		print_percent(ft_strdup("0"));
		printf("C %.2f,%.2f,%.2f %.2f,%.2f,%.2f %0.f\n",
			minirt->world.cam->origin.x,
			minirt->world.cam->origin.y, minirt->world.cam->origin.z,
			minirt->world.cam->target.x, minirt->world.cam->target.y,
			minirt->world.cam->target.z, minirt->world.cam->fov);
		render();
	}
	return (0);
}

int	loop_hook(void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	if (minirt->is_rendering)
		return (0);
	if (minirt->update)
	{
		fast_render();
		minirt->update = false;
	}
	return (0);
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
	minirt->size->mlx_img = mlx_new_image(minirt->win.mlx,
			minirt->size->width, minirt->size->height);
	if (!minirt->size->mlx_img)
		crash_exit(minirt, NULL, "mlx image malloc fail");
	minirt->size->data = mlx_get_data_addr(minirt->size->mlx_img,
			&minirt->size->bpp, &minirt->size->size_line,
			&minirt->size->endian);
	minirt->size->bppd = minirt->size->bpp >> 3;
	minirt->size->mlx = minirt->win.mlx;
	mlx_hook(minirt->win.windo, 17, 0, secure_exit, minirt);
	mlx_hook(minirt->win.windo, 2, 1L << 0, handle_key, minirt);
	mlx_loop_hook(minirt->win.mlx, loop_hook, minirt);
	mlx_expose_hook(minirt->win.windo, (void *)display, minirt);
	return (minirt);
}

t_minirt	*init_minirt(t_minirt *minirt, int argc, char **argv)
{
	static t_minirt	*minirt_;

	if (!minirt)
		return (minirt_);
	minirt_ = minirt;
	check_error(argc, argv, minirt);
	pars_map(&minirt);
	if (DEBUG)
		print_token(minirt, minirt->world.scene);
	return (minirt);
}

t_minirt	*get_minirt(void)
{
	static t_minirt	*minirt;

	if (!minirt)
		minirt = init_minirt(0, 0, 0);
	return (minirt);
}
