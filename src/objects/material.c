#include "objects.h"

t_mat	mat_metal(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.2,
		.spec = 0.9,
		.shin = 200,
		.reflect = 0.7,
		.transp = 0.0,
		.refract_idx = 1.5,
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}

t_mat	mat_plastic(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.7,
		.spec = 0.5,
		.shin = 50,
		.reflect = 0.2,
		.transp = 0.0,
		.refract_idx = 1.3,
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}

t_mat	mat_glass(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.1,
		.spec = 0.9,
		.shin = 300,
		.reflect = 0.9,
		.transp = 0.9,
		.refract_idx = 1.5,
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}

t_mat	mat_mirror(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.0,
		.spec = 1.0,
		.shin = 500,
		.reflect = 1.0,
		.transp = 0.0,
		.refract_idx = 1.0,
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}

t_mat	mat_wood(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.8,
		.spec = 0.2,
		.shin = 30,
		.reflect = 0.1,
		.transp = 0.0,
		.refract_idx = 1.0,
		.pattern = pattern(),
		.bumpmap = load_bumpmap("textures/wood.pgm")
	});
}
