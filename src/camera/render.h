#ifndef RENDER_H
# define RENDER_H

# include "camera.h"
# include "image.h"

# define MAX_REFLECT 10
# define PREVIEW_PIXEL_SIZE 7

//	pixelate: Pixelate the image
//	@param image The image to pixelate
//	@param color The color to pixelate with
//	@param x The x coordinate of the first pixel
//	@param y The y coordinate of the first pixel
void	pixelate(t_image *image, t_color color, int x, int y);
//	put_pixel_to_image: Put a pixel to the image
//	@param image The image to put the pixel to
//	@param x The x coordinate of the pixel
//	@param y The y coordinate of the pixel
//	@param color The color of the pixel
void	put_pixel_to_image(void *img, int x, int y, int color);
//	display: Display the buffered image in the window
void	display(void);
//	fast_render: Render the camera fast
void	fast_render(void);
//	render: Render the camera
void	render(void);
//	print_percent: Print the percentage of the rendering
//	@param info The percentage to print
void	print_percent(char *info);
//	print_message: Print a message to the screen
//	@param msg The message to print
void	print_message(char *msg);

#endif