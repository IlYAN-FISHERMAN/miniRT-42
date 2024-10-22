#include "render.h"
#include "../exit_handler/exit_handler.h"

int	global_render(int *p, bool fast)
{
	return (color_hex(color_at(ray_for_pixel
				(get_minirt()->world.cam, p[1], p[0]), fast, MAX_REFLECT)));
}

void	render(void)
{
	t_minirt	*mrt;
	int			p[2];
	int			percent[2];

	mrt = get_minirt();
	mrt->is_rendering = true;
	percent[0] = 0;
	percent[1] = mrt->size->height * mrt->size->width;
	p[0] = -1;
	while (++p[0], p[0] < mrt->size->height)
	{
		p[1] = -1;
		while (++p[1], p[1] < mrt->size->width)
		{
			if (!(++percent[0] % 100000))
				print_percent(ft_itoa((percent[0] * 100) / percent[1]));
			put_pixel_to_image(mrt->size->mlx_img, p[1], p[0],
				global_render(p, true));
		}
	}
	display();
}
