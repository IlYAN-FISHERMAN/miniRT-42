#include "matrix.h"

t_matrix4	m4identity(t_matrix4 m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				m.data[i][j] = 1;
			else
				m.data[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

t_matrix4	m4transpose(t_matrix4 m)
{
	t_matrix4	res;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.data[i][j] = m.data[j][i];
			j++;
		}
		i++;
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
	float	res;
	int		i;

	res = 0;
	i = -1;
	while (++i < 4)
		res += m.data[0][i] * m4cofactor(m, 0, i);
	return (res);
}
