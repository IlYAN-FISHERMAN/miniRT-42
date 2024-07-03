#ifndef CAMERA_H
# define CAMERA_H

# include "../objects/shapes.h"
# include "../rays/rays.h"

typedef struct s_camera
{
	t_point3		origin;
	t_vector3		forward;
	t_vector3		up;
	t_vector3		right;
	float			h;
	float			w;
}	t_camera;

//	new_camera: Create a new camera, note that fov is not set by default
//  @param origin The origin of the camera
//  @param target The target of the camera
//  @param upguide The upguide of the camera
//  @return A new camera
t_camera	*new_camera(t_point3 origin, t_vector3 target, t_vector3 upguide);

//	set_fov: Set the field of view of the camera
//  @param camera The camera to set the field of view of
//  @param fov The field of view to set
//  @param aspect The aspect ratio of the camera
//  @return The camera with the field of view set
t_camera	*set_fov(t_camera *camera, float fov, float aspect);

//	make_ray: Create a ray from the camera to a point on the screen
//  @param camera The camera to create the ray from
//  @param point The point on the screen to create the ray to
//  @return The ray from the camera to the point on the screen
t_ray		make_ray(t_camera *camera, t_vector2 point);

#endif