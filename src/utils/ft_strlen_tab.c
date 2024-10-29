/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:42:49 by ilyanar           #+#    #+#             */
/*   Updated: 2024/10/28 23:42:49 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	ft_strlen_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str && str[++i])
		;
	return (i);
}
