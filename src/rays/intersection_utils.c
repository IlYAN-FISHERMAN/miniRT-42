/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:37 by rude-jes          #+#    #+#             */
/*   Updated: 2024/10/28 22:53:38 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"

t_xs_parent	xs(void)
{
	return ((t_xs_parent){.count = 0, .xs = 0});
}

t_xs_parent	mergef_intersections(t_xs_parent xs1, t_xs_parent xs2)
{
	int			i;
	t_xs_parent	rslt;

	rslt = xs();
	i = -1;
	while (++i, i < xs1.count)
		add_intersection(&rslt, xs1.xs[i]);
	gfree(xs1.xs);
	i = -1;
	while (++i, i < xs2.count)
		add_intersection(&rslt, xs2.xs[i]);
	gfree(xs2.xs);
	return (rslt);
}
