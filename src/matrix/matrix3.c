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

double	m3minor(t_matrix3 m, int row, int col)
{
	return (m2det(m2subm(m, row, col)));
}

double	m3cofactor(t_matrix3 m, int row, int col)
{
	if ((row + col) % 2)
		return (-m3minor(m, row, col));
	return (m3minor(m, row, col));
}

double	m3det(t_matrix3 m)
{
	double	res;
	int		i;

	res = 0;
	i = -1;
	while (++i < 3)
		res += m.data[0][i] * m3cofactor(m, 0, i);
	return (res);
}

/*
// Computing Cofactors

int	main() {
	t_matrix3	m3 = {
		.data = {
			{ 1, 2, 6 },
			{ -5, 8, -4 },
			{ 2, 6, 4 }
		}
	};

	printf("cofactor [0;0]: %f\n", m3cofactor(m3, 0, 0));
	printf("cofactor [0;1]: %f\n", m3cofactor(m3, 0, 1));
	printf("cofactor [0;2]: %f\n", m3cofactor(m3, 0, 2));
	printf("det: %f\n", m3det(m3));

	t_matrix4	m4 = {
		.data = {
			{ -2, -8, 3, 5 },
			{ -3, 1, 7, 3 },
			{ 1, 2, -9, 6 },
			{ -6, 7, 7, -9 }
		}
	};

	printf("cofactor [0;0]: %f\n", m4cofactor(m4, 0, 0));
	printf("cofactor [0;1]: %f\n", m4cofactor(m4, 0, 1));
	printf("cofactor [0;2]: %f\n", m4cofactor(m4, 0, 2));
	printf("cofactor [0;3]: %f\n", m4cofactor(m4, 0, 3));
	printf("det: %f\n", m4det(m4));
}*/