/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:43:46 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:43:48 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	pars_map(t_minirt **minirt)
{
	char	**str;
	char	*gnl;

	create_default_mat(minirt);
	get_standard_size(minirt);
	while (true)
	{
		gnl = ft_get_next_line((*minirt)->fd);
		if (!gnl)
			break ;
		if (gnl[0] != '\n' && correct_dl(gnl))
		{
			str = ft_split_sp_tab(gnl);
			if (!str)
				crash_exit(*minirt,
					(char *[]){"miniRT", "parsing", NULL}, "Malloc fail");
			pars_obj(str, minirt);
			ft_free_tab(str);
		}
		gfree(gnl);
	}
	if (check_standard_shape(*minirt) && !(*minirt)->size)
		get_size_default(minirt);
}
