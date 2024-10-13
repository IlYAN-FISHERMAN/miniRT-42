#include "camera/image.h"
#include "parsing/parsing.h"
#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_minirt	minirt;
	int			i;
	int			j;

	ft_bzero(&minirt, sizeof(minirt));
	init_minirt(&minirt, argc, argv);
	init_minirt_mlx(&minirt);
	render();
	printf("rendered\n");
	i = -1;
	while (++i < minirt.size->height)
	{
		j = -1;
		while (++j < minirt.size->width)
			mlx_pixel_put(minirt.win.mlx, minirt.win.windo, j, i,
				minirt.size->data[i][j]);
	}
	printf("rendered\n");
	mlx_loop(minirt.win.mlx);
	exit(0);
}
