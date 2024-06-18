#ifndef PLANE_H
# define PLANE_H

# include "objects.h"

typedef struct s_plane {
	t_point		origin;
	t_vector	normal;
}	t_plane;

//  new_raw_plane: Create a new plane
//  origin: The origin of the plane
//  normal: The normal of the plane
//  Returns: A new plane
t_plane		*new_raw_plane(t_point origin, t_vector normal);

//  new_plane: Create a new plane object
//  origin: The origin of the plane
//  normal: The normal of the plane
//  Returns: A new plane object
t_object	*new_plane(t_point origin, t_vector normal);

#endif