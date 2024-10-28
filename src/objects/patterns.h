#ifndef PATTERNS_H
# define PATTERNS_H

# include "../color/color.h"
# include "../matrix/matrix.h"

typedef struct s_pattern	t_pattern;
typedef struct s_pattern
{
	bool		has_pattern;
	t_color		a;
	t_color		b;
	t_color		(*pattern_at_object)(t_pattern, void *, t_point3);
	t_matrix4	transform;
	t_matrix4	inv_transform;
}	t_pattern;

//	abs_pattern: Create a null pattern
//	@return The null pattern
t_pattern	pattern(void);

//	stripe_pattern: Create a stripe pattern
//	@param a The first color
//	@param b The second color
//	@return The stripe pattern
t_pattern	stripe_pattern(t_color a, t_color b);

//	checkboard_pattern: Create a checkboard pattern
//	@param a The first color
//	@param b The second color
//	@return The checkboard pattern
t_pattern	checkboard_pattern(t_color a, t_color b);

#endif