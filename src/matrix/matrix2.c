#include "matrix.h"

t_matrix2	m4subm(t_matrix3 m, int row, int col)
{
	t_matrix2	res;
	int			i[2];
	int			j[2];

	ft_memset(i, -1, sizeof(int) * 2);
	while (++(i[0]), i[0] < 3 && i[1] < 2)
	{
		if (i[0] == row)
			continue ;
		ft_memset(j, -1, sizeof(int) * 2);
		while (++(j[0]), j[0] < 3 && j[1] < 2)
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

double	m2det(t_matrix2 m)
{
	return (m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0]);
}
