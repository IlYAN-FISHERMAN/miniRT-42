#ifndef OBJECTS_H
# define OBJECTS_H

# include "../../libs/betterft/betterft.h"
# include "../vectors/vectors.h"

typedef enum e_objects_type {
	o_plane,
	o_sphere,
}	t_objects_type;

typedef struct s_object {
	t_objects_type	*type;
	void			*object;
}	t_object;

#endif