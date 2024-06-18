#ifndef PLANE_H
# define PLANE_H

# include "objects.h"

typedef struct s_plane {
	t_point		origin;
	t_vector	normal;
}	t_plane;

//  new_raw_plane: Create a new plane
//  @param origin The origin of the plane
//  @param normal The normal of the plane
//  @return A new plane
t_plane		*new_raw_plane(t_point origin, t_vector normal);

//  new_plane: Create a new plane object
//  @param origin The origin of the plane
//  @param normal The normal of the plane
//  @return A new plane object
t_object	*new_plane(t_point origin, t_vector normal);

#endif