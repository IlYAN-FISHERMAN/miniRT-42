/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:44:49 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:44:50 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_handler.h"

void	free_mat(void *content)
{
	if (((t_define *)content)->mat.bumpmap)
	{
		gfree(((t_define *)content)->mat.bumpmap->data);
		gfree(((t_define *)content)->mat.bumpmap);
	}
	gfree(((t_define *)content)->name);
	gfree(content);
}
