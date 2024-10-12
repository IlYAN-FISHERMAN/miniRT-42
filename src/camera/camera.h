#ifndef CAMERA_H
# define CAMERA_H

# include "../objects/shape.h"
# include "../rays/rays.h"

typedef struct s_camera
{
	t_point3		origin;
	t_vector3		target;
	float			fov;
	float			hsize;
	float			vsize;
	float			fov_rad;
	t_matrix4		transform;
	float			aspect_ratio;
	float			pixel_size;
	float			half_width;
	float			half_height;
	float			half_view;
}	t_camera;

//	new_camera: Create a new camera, note that fov is not set by default
//  @param origin The origin of the camera
//  @param target The target of the camera
//  @param fov The field of view of the camera
//  @return A new camera
t_camera	*new_camera(t_point3 origin, t_vector3 target, float fov);

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

#endif
