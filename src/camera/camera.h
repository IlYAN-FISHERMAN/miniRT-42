#ifndef CAMERA_H
# define CAMERA_H

# include "../objects/shape.h"
# include "../rays/rays.h"

// Controls of camera movements
# ifdef __linux__
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_SPACE	32
#  define KEY_X	120
#  define KEY_LEFT	65361
#  define KEY_UP		65362
#  define KEY_RIGHT	65363
#  define KEY_DOWN	65364
#  define KEY_R		114
#  define KEY_ESC		65307
#  define KEY_ENTER	65293
# endif
# ifdef __APPLE__
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_SPACE	49
#  define KEY_X	7
#  define KEY_LEFT	123
#  define KEY_UP		126
#  define KEY_RIGHT	124
#  define KEY_DOWN	125
#  define KEY_R		15
#  define KEY_ESC		53
#  define KEY_ENTER	36
# endif

typedef struct s_camera
{
	t_point3		origin;
	t_point3		c_origin;
	t_vector3		target;
	t_vector3		up;
	double			fov;
	double			hsize;
	double			vsize;
	double			fov_rad;
	t_matrix4		transform;
	double			aspect_ratio;
	double			pixel_size;
	double			half_width;
	double			half_height;
	double			half_view;
	t_matrix4		inv_transform;
}	t_camera;

//	new_camera: Create a new camera, note that fov is not set by default
//  @param origin The origin of the camera
//  @param target The target of the camera
//  @param fov The field of view of the camera
//  @return A new camera
t_camera	*new_camera(t_point3 origin, t_vector3 target, double fov);

//	view_transform: Create a view transform matrix
//  @param from The origin of the camera
//  @param to The target of the camera
//  @param up The upguide of the camera
//  @return The view transform matrix
t_matrix4	view_transform(t_point3 from, t_point3 to, t_vector3 up);

//	ray_for_pixel: Create a ray for a pixel
//  @param camera The camera to create the ray from
//  @param x The x coordinate of the pixel
//  @param y The y coordinate of the pixel
//  @return The ray for the pixel
t_ray		ray_for_pixel(t_camera *camera, int x, int y);

//	camera_move: Moves the camera based on keycode
//	@param key The keycode
void		camera_move(int key);

#endif
