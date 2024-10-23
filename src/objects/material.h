#ifndef MATERIAL_H
# define MATERIAL_H

# include "objects.h"

typedef t_list			t_mats;

typedef struct s_define
{
	char	*name;
	t_mat	mat;
}	t_define;

typedef struct s_dfmat
{
	t_mat	metal;
	t_mat	platic;
	t_mat	glass;
	t_mat	mirror;
	t_mat	wood;
}	t_dfmat;

t_mat	mat_metal(t_color color);
t_mat	mat_plastic(t_color color);
t_mat	mat_glass(t_color color);
t_mat	mat_mirror(t_color color);
t_mat	mat_wood(t_color color);

#endif
