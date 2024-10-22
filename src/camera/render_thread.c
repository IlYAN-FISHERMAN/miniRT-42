#include "render.h"
#include "../exit_handler/exit_handler.h"

int	global_render(int *p, bool fast)
{
	return (color_hex(color_at(ray_for_pixel
				(get_minirt()->world.cam, p[1], p[0]), fast, MAX_REFLECT)));
}

static void	*thread_render(void *data_)
{
	t_thread_data	*data;
	int				p[2];
	t_minirt		*minirt;

	minirt = get_minirt();
	data = (t_thread_data *)data_;
	p[0] = -1;
	while (p[0] < minirt->size->height)
	{
		pthread_mutex_lock(data->pos_mutex);
		p[0] = data->p[0];
		data->p[0]++;
		pthread_mutex_unlock(data->pos_mutex);
		if (p[0] >= minirt->size->height)
			break ;
		p[1] = 0;
		while (p[1] < minirt->size->width)
		{
			put_pixel_to_image(minirt->size, p[1], p[0],
				global_render(p, true));
			p[1]++;
		}
		if ((p[0] * 100 / data->perc) % 13 == 0)
		{
			pthread_mutex_lock(data->perc_mutex);
			print_percent(ft_itoa((p[0] * 100) / data->perc));
			pthread_mutex_unlock(data->perc_mutex);
		}
	}
	return (0);
}

void	render(void)
{
	t_minirt		*minirt;
	int				p[2];
	int				percent;
	t_thread_data	thread_data;
	pthread_mutex_t	mutex[3];

	minirt = get_minirt();
	minirt->is_rendering = true;
	p[0] = 0;
	p[1] = 0;
	pthread_mutex_init(&mutex[0], NULL);
	pthread_mutex_init(&mutex[1], NULL);
	pthread_mutex_init(&mutex[2], NULL);
	thread_data.image_mutex = &mutex[0];
	thread_data.pos_mutex = &mutex[1];
	thread_data.perc_mutex = &mutex[2];
	thread_data.p = p;
	percent = minirt->size->height;
	thread_data.perc = percent;
	thread_data.fast = false;
	start_threads(thread_render, (void *)&thread_data);
	stop_threads();
	display();
}
