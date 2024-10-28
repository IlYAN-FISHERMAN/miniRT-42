/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:38 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:53:38 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (xs.xs[i].t > RAY_T_MIN
			&& (!hit || xs.xs[i].t < hit->t))
			hit = &xs.xs[i];
		i++;
	}
	return (hit);
}

t_intersect	intersection(double t, t_object *object)
{
	t_intersect	intersect;

	intersect.t = t;
	intersect.object = object;
	return (intersect);
}

t_xs_parent	intersections(t_xs_parent set)
{
	int			i;
	t_intersect	tmp;

	i = -1;
	while (++i, i < set.count)
	{
		if (i + 1 < set.count && set.xs[i].t > set.xs[i + 1].t)
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
