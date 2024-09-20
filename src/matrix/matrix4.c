#include "matrix.h"

t_matrix4	m4identity(t_matrix4 m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				m.data[i][j] = 1;
			else
				m.data[i][j] = 0;
		}
	}
	return (m);
}

t_matrix4	m4transpose(t_matrix4 m)
{
	t_matrix4	res;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res.data[i][j] = m.data[j][i];
	}
	return (res);
}

float	m4minor(t_matrix4 m, int row, int col)
{
	return (m3det(m3subm(m, row, col)));
}

float	m4cofactor(t_matrix4 m, int row, int col)
{
	if ((row + col) % 2)
		return (-m4minor(m, row, col));
	return (m4minor(m, row, col));
}

float	m4det(t_matrix4 m)
{
	return (
		m.data[0][0] * (m.data[1][1] * (m.data[2][2] * m.data[3][3] -
			m.data[2][3] * m.data[3][2]) - m.data[1][2] * (m.data[2][1] *
			m.data[3][3] - m.data[2][3] * m.data[3][1]) + m.data[1][3] *
			(m.data[2][1] * m.data[3][2] - m.data[2][2] * m.data[3][1])
		) -
		m.data[0][1] * (m.data[1][0] * (m.data[2][2] * m.data[3][3] -
			m.data[2][3] * m.data[3][2]) - m.data[1][2] * (m.data[2][0] *
			m.data[3][3] - m.data[2][3] * m.data[3][0]) + m.data[1][3] *
			(m.data[2][0] * m.data[3][2] - m.data[2][2] * m.data[3][0])
		) +
		m.data[0][2] * (m.data[1][0] * (m.data[2][1] * m.data[3][3] -
			m.data[2][3] * m.data[3][1]) - m.data[1][1] * (m.data[2][0] *
			m.data[3][3] - m.data[2][3] * m.data[3][0]) + m.data[1][3] *
			(m.data[2][0] * m.data[3][1] - m.data[2][1] * m.data[3][0])
		) -
		m.data[0][3] * (m.data[1][0] * (m.data[2][1] * m.data[3][2] -
			m.data[2][2] * m.data[3][1]) - m.data[1][1] * (m.data[2][0] *
			m.data[3][2] - m.data[2][2] * m.data[3][0]) + m.data[1][2] *
			(m.data[2][0] * m.data[3][1] - m.data[2][1] * m.data[3][0])
		)
	);
}
