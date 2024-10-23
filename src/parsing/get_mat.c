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

t_mat	get_dfmat(char *str, t_color color)
{
	if (!ft_strcmp(str, "metal"))
		return (mat_metal(color));
	if (!ft_strcmp(str, "plastic"))
		return (mat_plastic(color));
	if (!ft_strcmp(str, "glass"))
		return (mat_glass(color));
	if (!ft_strcmp(str, "mirror"))
		return (mat_mirror(color));
	if (!ft_strcmp(str, "wood"))
		return (mat_wood(color));
	return (dfmaterial(color));
}

void	create_default_mat(t_minirt **minirt)
{
	(*minirt)->df_mat = (t_dfmat){.metal = mat_metal(color(0, 0, 0)), \
		.wood = mat_wood(color(0, 0, 0)), .glass = mat_glass(color(0, 0, 0)),
		.mirror = mat_mirror(color(0, 0, 0)), .platic
		= mat_plastic(color(0, 0, 0))};
}
