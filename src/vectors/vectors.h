#ifndef VECTORS_H
# define VECTORS_H

# include "../../libs/betterft/betterft.h"

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef t_vector	t_point;

//	vlength: Length of a vector
//	Returns: The length of the vector as a scalar
float	vlength(t_vector v);

//	vadd: Add two vectors
//	Returns: The sum of the two vectors as a new vector
t_vector	vadd(t_vector v, t_vector u);

//	vsub: Subtract two vectors
//	Returns: The difference of the two vectors as a new vector
t_vector	vsub(t_vector v, t_vector u);

//	vmul: Multiply a vector by a scalar
//	Returns: The product of the vector and the scalar as a new vector
t_vector	vmul(t_vector v, float scalar);

//	vdiv: Divide a vector by a scalar
//	Returns: The quotient of the vector and the scalar as a new vector
t_vector	vdiv(t_vector v, float scalar);

//	vdot: Dot product of two vectors
//	A dot product is a scalar that is the sum of the products of the corresponding components of the two vectors
//	Returns: The dot product of the two vectors as a scalar
float	vdot(t_vector v, t_vector u);

//	vcross: Cross product of two vectors
//	A cross product is a vector that is perpendicular to the two vectors
//	Returns: The cross product of the two vectors as a new vector
t_vector	vcross(t_vector v, t_vector u);

//	vnormalized: Normalize a vector
//	Returns: The normalized vector as a new vector
t_vector	vnormalized(t_vector v);

//	vnormalize: Normalize a vector
//	Returns: Normalize and return the vector as a pointer
t_vector	*vnormalize(t_vector *v);

#endif