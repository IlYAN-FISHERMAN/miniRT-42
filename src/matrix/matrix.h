#ifndef MATRIX_H
# define MATRIX_H

# include "../vectors/vectors.h"

typedef struct s_matrix4
{
    float data[4][4];
}   t_matrix4;

typedef struct s_matrix3
{
    float data[3][3];
}   t_matrix3;

typedef struct s_matrix2
{
    float data[2][2];
}   t_matrix2;

// m4mul: Multiply two matrices
// @param m The first matrix
// @param n The second matrix
// @return The multiplied matrix
t_matrix4   m4mul(t_matrix4 m, t_matrix4 n);
//  m4mulv: Multiply a matrix by a vector
//  @param m The matrix
//  @param v The vector
//  @return The multiplied vector
t_vector3   vm4mul(t_matrix4 m, t_vector 3 v);
//  m4identity: Get the identity matrix of a given matrix
//  @param m The matrix
//  @return The identity matrix
t_matrix4   m4identity(t_matrix4 m);
//  m4rotate: Invert columns and rows of a matrix
//  @param m The matrix
//  @return The rotated matrix
t_matrix4   m4rotate(t_matrix4 m);

#endif