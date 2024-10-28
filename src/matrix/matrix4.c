/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:51:39 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:51:40 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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

double	m4minor(t_matrix4 m, int row, int col)
{
	return (m3det(m3subm(m, row, col)));
}

double	m4cofactor(t_matrix4 m, int row, int col)
{
	if ((row + col) % 2)
		return (-m4minor(m, row, col));
	return (m4minor(m, row, col));
}

double	m4det(t_matrix4 m)
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
