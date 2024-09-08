#ifndef MATRIX_H
# define MATRIX_H

# include "../vectors/vectors.h"

typedef struct s_matrix4
{
	double	data[4][4];
}	t_matrix4;

typedef struct s_matrix3
{
	double	data[3][3];
}	t_matrix3;

typedef struct s_matrix2
{
	double	data[2][2];
}	t_matrix2;

// m4mul: Multiply two matrices
// @param m The first matrix
// @param n The second matrix
// @return The multiplied matrix
t_matrix4	m4mul(t_matrix4 m, t_matrix4 n);
//  m4mulv: Multiply a matrix by a vector
//  @param m The matrix
//  @param v The vector
//  @return The multiplied vector
t_vector3	vm4mul(t_matrix4 m, t_vector3 v);
//  m4identity: Get the identity matrix of a given matrix
//  @param m The matrix
//  @return The identity matrix
t_matrix4	m4identity(t_matrix4 m);
//  m4transpose: Invert columns and rows of a matrix
//  @param m The matrix
//  @return The rotated matrix
t_matrix4	m4transpose(t_matrix4 m);
//  m3subm: Get the t_matrix3 submatrix of a t_matrix4
//  @param m The matrix
//  @param row The row to remove
//  @param col The column to remove
//  @return The submatrix
t_matrix3	m3subm(t_matrix4 m, int row, int col);
//  m2subm: Get the t_matrix2 submatrix of a t_matrix3
//  @param m The matrix
//  @param row The row to remove
//  @param col The column to remove
//  @return The submatrix
t_matrix2	m2subm(t_matrix3 m, int row, int col);
//  m3minor: Get the minor of a t_matrix3
//  @param m The matrix
//  @param row The row to remove
//  @param col The column to remove
//  @return The minor
double		m3minor(t_matrix3 m, int row, int col);
double		m2det(t_matrix2 m);

#endif
