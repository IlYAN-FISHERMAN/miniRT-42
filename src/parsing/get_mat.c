#include "ft_memory.h"
#include "ft_string.h"
#include "parsing.h"

t_mat	get_define_mat(char *str, t_mats *iter, t_color color)
{
	t_define	*tmp;

	while (iter)
	{
		tmp = iter->content;
		if (!ft_strcmp(str, tmp->name))
		{
			tmp->mat.color = color;
			return (tmp->mat);
		}
		iter = iter->next;
	}
	return ((t_mat){});
}

t_mat	get_dfmat(char *str, t_color color, t_minirt *minirt)
{
	t_mat	mat;

	ft_bzero(&mat, sizeof(t_mat));
	if (!ft_strcmp(str, "metal"))
		mat = minirt->df_mat.metal;
	else if (!ft_strcmp(str, "plastic"))
		mat = minirt->df_mat.platic;
	else if (!ft_strcmp(str, "glass"))
		mat = minirt->df_mat.glass;
	else if (!ft_strcmp(str, "mirror"))
		mat = minirt->df_mat.mirror;
	else if (!ft_strcmp(str, "wood"))
		mat = minirt->df_mat.wood;
	else if (!ft_strcmp(str, "checkerboard"))
		mat = minirt->df_mat.checkerboard;
	else if (!ft_strcmp(str, "bricks"))
		mat = minirt->df_mat.bricks;
	else if (!ft_strcmp(str, "mat"))
		mat = minirt->df_mat.mat;
	mat.color = color;
	return (mat);
}

void	create_default_mat(t_minirt **minirt)
{
	(*minirt)->df_mat = (t_dfmat){.metal = mat_metal(color(0, 0, 0)),
		.wood = mat_wood(color(0, 0, 0)), .glass = mat_glass(color(0, 0, 0)),
		.mirror = mat_mirror(color(0, 0, 0)), .platic
		= mat_plastic(color(0, 0, 0)),
		.checkerboard = mat_checkerboard(color(0, 0, 0)),
		.bricks = mat_bricks(color(0, 0, 0)), .mat = mat_mat(color(0, 0, 0))};
}
