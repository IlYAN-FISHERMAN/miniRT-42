#ifndef BUMPMAP_H
# define BUMPMAP_H

# include "../vectors/vectors.h"

# ifndef BUMP_SCALE
#  define BUMP_SCALE 1.0
# endif

typedef struct s_bumpmap
{
	t_byte	*data;
	size_t	width;
	size_t	height;
}	t_bumpmap;

//	load_bumpmap: Load a bumpmap from a pgm file
//	@param filename The file to load
//	@return The bumpmap address
t_bumpmap	*load_bumpmap(char *filename);

//	dfbumpmap: Default bumpmap
//	@return The default bumpmap
t_bumpmap	*dfbumpmap(void);

//	get_bumpv: Get the bumpmap value at a uv coordinate
//	@param bumpmap The bumpmap
//	@param uv The uv coordinate
//	@return The bumpmap value
double		get_bumpv(t_bumpmap *bumpmap, t_vector2 uv);

//	perturbn: Perturb the normal with a bump value
//	@param normal The normal
//	@param bump_value The bump value
//	@return The perturbed normal
t_vector3	perturbn(t_vector3 normal, double bump_value);

#endif