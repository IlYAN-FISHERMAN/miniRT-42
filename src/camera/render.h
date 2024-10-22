#ifndef RENDER_H
# define RENDER_H

# include "camera.h"
# include "image.h"

# define MAX_REFLECT 10
# define PREVIEW_PIXEL_SIZE 7

typedef struct s_thread_data
{
	int				*p;
	bool			fast;
	pthread_mutex_t	*image_mutex;
	pthread_mutex_t	*pos_mutex;
}	t_thread_data;

//	put_pixel_to_image: Put a pixel to the image
//	@param image The image to put the pixel to
//	@param x The x coordinate of the pixel
//	@param y The y coordinate of the pixel
//	@param color The color of the pixel
void		put_pixel_to_image(void *img, int x, int y, int color);
//	display: Display the buffered image in the window
void		display(void);
//	fast_render: Render the camera fast
void		fast_render(void);
//	render: Render the camera
void		render(void);
//	print_percent: Print the percentage of the rendering
//	@param info The percentage to print
void		print_percent(char *info);
//	print_message: Print a message to the screen
//	@param msg The message to print
void		print_message(char *msg);
//	global_render: Get the color of a pixel
//	@param p The pixel to get the color of
//	@param fast If the render is fast
int			global_render(int *p, bool fast);
//	get_thread: Get or create the threads
//	@return The threads null terminated
pthread_t	*get_thread(void);
//	start_threads: Start the threads
//	@param func The function to run in the threads
//	@param data The data to pass to the threads
//	@return The threads null terminated
pthread_t	*start_threads(void *(*func)(void *), void *data);
//	stop_threads: Stop the threads
void		stop_threads(void);

#endif