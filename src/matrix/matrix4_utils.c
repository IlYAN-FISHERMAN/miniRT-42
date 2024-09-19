#include "matrix.h"

t_matrix4	m4mul(t_matrix4 m, t_matrix4 n)
{
	t_matrix4	res;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.data[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				res.data[i][j] += m.data[i][k] * n.data[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

t_tuple4	tm4mul(t_matrix4 m, t_tuple4 t)
{
	return ((t_tuple4){
		m.data[0][0] * t.x + m.data[0][1] * t.y +
			m.data[0][2] * t.z + m.data[0][3] * t.w,
		m.data[1][0] * t.x + m.data[1][1] * t.y +
			m.data[1][2] * t.z + m.data[1][3] * t.w,
		m.data[2][0] * t.x + m.data[2][1] * t.y +
			m.data[2][2] * t.z + m.data[2][3] * t.w,
		m.data[3][0] * t.x + m.data[3][1] * t.y +
			m.data[3][2] * t.z + m.data[3][3] * t.w
	});
}

t_matrix4	*m4invert(t_matrix4 *m)
{
	float		det;
	t_matrix4	m_buff;
	int			i;
	int			j;

	det = m4det(*m);
	if (!det)
		return (0);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m_buff.data[i][j] = m4cofactor(*m, i, j);
	}
	m_buff = m4transpose(m_buff);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m->data[i][j] = m_buff.data[i][j] / det;
	}
	return (m);
}
