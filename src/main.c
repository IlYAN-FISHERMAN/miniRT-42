#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_minirt	*minirt;

	minirt = init_minirt(argc, argv);
	mlx_loop(minirt->mlx);
	exit(0);
}
