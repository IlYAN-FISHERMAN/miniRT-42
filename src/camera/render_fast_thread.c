#include "render.h"
#include "../exit_handler/exit_handler.h"

static void	pixelate(t_image *image, int color, int *p, t_thread_data *data)
{
	int	i;
	int	j;

	pthread_mutex_lock(data->image_mutex);
	i = -1;
	while (++i, i <= PREVIEW_PIXEL_SIZE && p[0] + i < image->height)
	{
		j = -1;
		while (++j, j <= PREVIEW_PIXEL_SIZE && p[1] + j < image->width)
			put_pixel_to_image(image->mlx_img, p[1] + j, p[0] + i, color);
	}
	pthread_mutex_unlock(data->image_mutex);
}

static void	*thread_fast_render(void *data)
{
	t_thread_data	*thread_data;
	int				p[2];
	t_minirt		*minirt;

	minirt = get_minirt();
	thread_data = (t_thread_data *)data;
	p[0] = 0;
	while (p[0] < minirt->size->height)
	{
		pthread_mutex_lock(thread_data->pos_mutex);
		p[0] = thread_data->p[0];
		thread_data->p[0] += PREVIEW_PIXEL_SIZE;
		pthread_mutex_unlock(thread_data->pos_mutex);
		if (p[0] >= minirt->size->height)
			break ;
		p[1] = 0;
		while (p[1] < minirt->size->width)
		{
			pixelate(minirt->size, global_render(p, true), p, thread_data);
			p[1] += PREVIEW_PIXEL_SIZE;
		}
	}
	return (0);
}

void	fast_render(void)
{
	t_minirt		*minirt;
	int				p[2];
	t_thread_data	thread_data;
	pthread_mutex_t	mutex[2];

	minirt = get_minirt();
	minirt->is_rendering = true;
	p[0] = 0;
	p[1] = 0;
	pthread_mutex_init(&mutex[0], NULL);
	pthread_mutex_init(&mutex[1], NULL);
	thread_data.image_mutex = &mutex[0];
	thread_data.pos_mutex = &mutex[1];
	thread_data.p = p;
	start_threads(thread_fast_render, (void *)&thread_data);
	stop_threads();
	display();
}
