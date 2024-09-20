#include "matrix.h"

t_matrix3	m3subm(t_matrix4 m, int row, int col)
{
	t_matrix3	res;
	int			i[2];
	int			j[2];

	ft_memset(i, -1, sizeof(int) * 2);
	while (++(i[0]), i[0] < 4 && i[1] < 3)
	{
		if (i[0] == row)
			continue ;
		ft_memset(j, -1, sizeof(int) * 2);
		while (++(j[0]), j[0] < 4 && j[1] < 3)
		{
			if (j[0] == col)
				continue ;
			j[1]++;
			res.data[i[1] + 1][j[1]] = m.data[i[0]][j[0]];
		}
		i[1]++;
	}
	return (res);
}

float	m3minor(t_matrix3 m, int row, int col)
{
	return (m2det(m2subm(m, row, col)));
}

float	m3cofactor(t_matrix3 m, int row, int col)
{
	if ((row + col) % 2)
		return (-m3minor(m, row, col));
	return (m3minor(m, row, col));
}

float	m3det(t_matrix3 m)
{
	return (
		m.data[0][0] *
		(m.data[1][1] * m.data[2][2] - m.data[1][2] * m.data[2][1]) -
		m.data[0][1] *
		(m.data[1][0] * m.data[2][2] - m.data[1][2] * m.data[2][0]) +
		m.data[0][2] *
		(m.data[1][0] * m.data[2][1] - m.data[1][1] * m.data[2][0])
	);
}
