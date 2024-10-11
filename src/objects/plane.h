#ifndef PLANE_H
# define PLANE_H

# include "objects.h"

typedef struct s_plane
{
	t_point3		origin;
	t_vector3		normal;
	t_color			color;
}	t_plane;

//  new_plane: Create a new plane object
//  @param origin The origin of the plane
//  @param normal The normal of the plane
//  @return A new plane object
t_object	*new_plane(t_point3 origin, t_vector3 normal, t_color color);

#endif