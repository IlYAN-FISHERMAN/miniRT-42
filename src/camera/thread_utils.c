#include "render.h"
#include "../exit_handler/exit_handler.h"

pthread_t	*get_thread(void)
{
	static pthread_t	*thread;
	long				nb_thread;

	if (thread)
		return (thread);
	nb_thread = sysconf(_SC_NPROCESSORS_ONLN);
	thread = galloc(sizeof(pthread_t) * (nb_thread + 1));
	if (!thread)
		crash_exit(get_minirt(), NULL, "Thread malloc failed");
	memset(thread, 1, sizeof(pthread_t) * (nb_thread + 1));
	thread[nb_thread] = 0;
	return (thread);
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

void	stop_threads(void)
{
	pthread_t	*thread;
	int			i;

	thread = get_thread();
	i = -1;
	while (++i, thread[i])
		pthread_join(thread[i], NULL);
}