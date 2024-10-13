#include "intersect.h"
#include "../exit_handler/exit_handler.h"

t_intersect	*hit(t_xs_parent xs)
{
	int			i;
	t_intersect	*hit;

	hit = 0;
	i = 0;
	while (i < xs.count)
	{
		if (xs.xs[i].t > RAY_T_MIN && xs.xs[i].t <= RAY_T_MAX
			&& (!hit || xs.xs[i].t < hit->t))
			hit = &xs.xs[i];
		i++;
	}
	return (hit);
}

t_intersect	intersection(float t, t_object *object)
{
	t_intersect	intersect;

	intersect.t = t;
	intersect.object = object;
	return (intersect);
}

/**
 * del_intersection: Delete an intersection from the intersection set
 * @param xs The intersection set
 * @param i The index of the intersection to delete
 * @return A pointer to the updated intersection set
 */
static t_xs_parent	*del_intersection(t_xs_parent *xs, int i)
{
	int			j;
	t_intersect	tmp;

	j = i;
	while (j + 1 < xs->count)
	{
		tmp = xs->xs[j];
		xs->xs[j] = xs->xs[j + 1];
		xs->xs[j + 1] = tmp;
		j++;
	}
	xs->xs = ft_reallocf(xs->xs, xs->count * sizeof(t_intersect),
			(xs->count - 1) * sizeof(t_intersect));
	xs->count--;
	return (xs);
}

t_xs_parent	intersections(t_xs_parent set)
{
	int			i;
	t_intersect	tmp;

	i = -1;
	while (++i, i < set.count)
	{
		if (set.xs[i].t > RAY_T_MAX)
		{
			del_intersection(&set, i);
			i = -1;
		}
		else if (i + 1 < set.count && set.xs[i].t > set.xs[i + 1].t
			&& set.xs[i + 1].t <= RAY_T_MAX)
		{
			tmp = set.xs[i];
			set.xs[i] = set.xs[i + 1];
			set.xs[i + 1] = tmp;
			i = -1;
		}
	}
	return (set);
}

t_xs_parent	*add_intersection(t_xs_parent *xs, t_intersect i)
{
	xs->xs = ft_reallocf(xs->xs, xs->count * sizeof(t_intersect),
			(xs->count + 1) * sizeof(t_intersect));
	if (!xs->xs)
		crash_exit(get_minirt(), (char *[]){"miniRT:",
			"render", 0}, "Intersection set allocation failed");
	xs->xs[xs->count] = i;
	xs->count++;
	return (xs);
}
