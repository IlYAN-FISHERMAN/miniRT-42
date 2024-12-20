/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:49:07 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:49:09 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "../miniRT.h"
#include "ft_memory.h"

static void	camera_pos_move(int key, t_camera *cam)
{
	t_vector3	side;
	t_vector3	move;

	side = vmul(vnormalized(vcross(vector3(0, 1, 0), cam->target)), 0.5);
	move = vmul((cam->target), 0.5);
	move.y = 0;
	if (key == KEY_D)
		cam->origin = vadd(cam->origin, side);
	else if (key == KEY_A)
		cam->origin = vsub(cam->origin, side);
	else if (key == KEY_W)
		cam->origin = vadd(cam->origin, move);
	else if (key == KEY_S)
		cam->origin = vsub(cam->origin, move);
	else if (key == KEY_SPACE)
		cam->origin.y += 0.5;
	else if (key == KEY_X)
		cam->origin.y -= 0.5;
}

static void	camera_dir_move(int key, t_camera *cam)
{
	t_vector3	right;
	t_matrix4	rot;

	ft_bzero(&rot, sizeof(t_matrix4));
	right = vnormalized(vcross(cam->up, cam->target));
	if (key == KEY_LEFT)
		rot = m4rotating(-0.05, Y_AXIS);
	else if (key == KEY_RIGHT)
		rot = m4rotating(0.05, Y_AXIS);
	else if (key == KEY_UP)
		rot = m4rodrig_rot(right, -0.05);
	else if (key == KEY_DOWN)
		rot = m4rodrig_rot(right, 0.05);
	cam->target = tm4mul(rot, cam->target);
}

void	camera_move(int key)
{
	t_minirt	*minirt;
	t_camera	*cam;

	minirt = get_minirt();
	cam = minirt->world.cam;
	if (key == KEY_R)
	{
		cam->origin = point3(0, 1.8, 0);
		cam->target = vector3(0, -0.01, 1);
	}
	else if (key == KEY_D || key == KEY_A || key == KEY_W || key == KEY_S
		|| key == KEY_SPACE || key == KEY_X)
		camera_pos_move(key, cam);
	else if (key == KEY_LEFT || key == KEY_UP
		|| key == KEY_RIGHT || key == KEY_DOWN)
		camera_dir_move(key, cam);
	minirt->world.cam = new_camera(cam->origin, cam->target, cam->fov);
	gfree(cam);
}
