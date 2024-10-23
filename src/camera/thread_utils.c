#include "render.h"
#include "../exit_handler/exit_handler.h"

pthread_t	*get_thread(void)
{
	t_minirt			*minirt;
	long				nb_thread;

	minirt = get_minirt();
	if (minirt->threads)
		return (minirt->threads);
	nb_thread = sysconf(_SC_NPROCESSORS_ONLN);
	minirt->threads = galloc(sizeof(pthread_t) * (nb_thread + 1));
	if (!minirt->threads)
		crash_exit(get_minirt(), NULL, "Thread malloc failed");
	memset(minirt->threads, 1, sizeof(pthread_t) * (nb_thread + 1));
	minirt->threads[nb_thread] = 0;
	return (minirt->threads);
}

pthread_t	*start_threads(void *(*func)(void *), void *data)
{
	pthread_t	*thread;
	int			i;

	thread = get_thread();
	i = -1;
	while (++i, thread[i])
	{
		if (pthread_create(&thread[i], NULL, func, data))
			crash_exit(get_minirt(), NULL, "Thread creation failed");
	}
	return (thread);
}

void	stop_threads(t_thread_data *data)
{
	pthread_t	*thread;
	int			i;

	thread = get_thread();
	i = -1;
	while (++i, thread[i])
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(data->image_mutex);
	pthread_mutex_destroy(data->pos_mutex);
	if (data->perc_mutex)
		pthread_mutex_destroy(data->perc_mutex);
}
