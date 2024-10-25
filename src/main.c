#include "miniRT.h"

static void	post_parsing(t_minirt *minirt)
{
	minirt->world.amb->c_rgb
		= color_scalar(minirt->world.amb->rgb, minirt->world.amb->light);
}

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	ft_bzero(&minirt, sizeof(minirt));
	init_minirt(&minirt, argc, argv);
	post_parsing(&minirt);
	init_minirt_mlx(&minirt);
	fast_render();
	mlx_loop(minirt.win.mlx);
	exit(0);
}
