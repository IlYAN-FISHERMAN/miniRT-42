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

//	vlength: Get the length of a vector
//	@param v The vector
//	@return The length of the vector
float		vlength(t_vector v);

//	vlength2: Get the squared length of a vector
//	@param v The vector
//	@return The squared length of the vector
float		vlength2(t_vector v);

//	vadd: Add two vectors
//	@param v The first vector
//	@param u The second vector
//	@return The sum of the two vectors
t_vector	vadd(t_vector v, t_vector u);

//	vsub: Subtract two vectors
//	@param v The first vector
//	@param u The second vector
//	@return The difference of the two vectors
t_vector	vsub(t_vector v, t_vector u);

//	vmul: Multiply a vector by a scalar
//	@param v The vector
//	@param scalar The scalar
//	@return The product of the vector and the scalar
t_vector	vmul(t_vector v, float scalar);

//	vdiv: Divide a vector by a scalar
//	@param v The vector
//	@param scalar The scalar
//	@return The quotient of the vector and the scalar
t_vector	vdiv(t_vector v, float scalar);

//	vdot: Get the dot product of two vectors
//	@param v The first vector
//	@param u The second vector
//	@return The dot product of the two vectors
float		vdot(t_vector v, t_vector u);

//	vcross: Get the cross product of two vectors
//	@param v The first vector
//	@param u The second vector
//	@return The cross product of the two vectors
t_vector	vcross(t_vector v, t_vector u);

//	vnormalized: Normalize a vector
//	@param v The vector
//	@return The normalized vector
t_vector	vnormalized(t_vector v);

//	vnormalize: Normalize a vector
//	@param v The vector
//	@return The normalized vector
t_vector	*vnormalize(t_vector *v);

#endif