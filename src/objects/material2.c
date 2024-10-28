#include "objects.h"

t_mat	mat_checkerboard(t_color c)
{
	return ((t_mat){
		.color = c,
		.diff = 0.7,
		.spec = 0.5,
		.shin = 50,
		.reflect = 0.0,
		.transp = 0.0,
		.refract_idx = 1.3,
		.pattern = checkboard_pattern(color(0, 0, 0), color(255, 255, 255)),
		.bumpmap = dfbumpmap()
	});
}

t_mat	mat_bricks(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.8,
		.spec = 0.1,
		.shin = 10,
		.reflect = 0.0,
		.transp = 0.0,
		.refract_idx = 1.0,
		.pattern = pattern(),
		.bumpmap = load_bumpmap("textures/stylized_bricks.pgm")
	});
}

t_mat	mat_mat(t_color color)
{
	return ((t_mat){
		.color = color,
		.diff = 0.9,
		.spec = 0.9,
		.shin = 200,
		.reflect = 0.0,
		.transp = 0.0,
		.refract_idx = 1.0,
		.pattern = pattern(),
		.bumpmap = dfbumpmap()
	});
}
