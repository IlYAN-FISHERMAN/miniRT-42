#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	init_minirt(&minirt, argc, argv);
	init_minirt_mlx(&minirt);
	mlx_loop(minirt.win.mlx);
	exit(0);
}
