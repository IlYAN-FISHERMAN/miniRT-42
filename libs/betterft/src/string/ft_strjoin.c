/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:04:30 by rude-jes          #+#    #+#             */
/*   Updated: 2024/09/20 17:44:06 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)galloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s3)
		return (0);
	ft_memcpy(s3, s1, s1_len);
	ft_memcpy((s3 + s1_len), s2, s2_len);
	s3[s1_len + s2_len] = 0;
	return (s3);
}

char	*ft_joint_all(char **str)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = 0;
	i = 1;
	if (!str)
		return (NULL);
	if (str && str[0])
		tmp1 = ft_strdup(str[0]);
	while (str[i])
	{
		tmp2 = ft_strjoin(tmp1, str[i]);
		gfree(tmp1);
		i++;
		if (!str[i])
			return (tmp2);
		tmp1 = ft_strjoin(tmp2, str[i]);
		gfree(tmp2);
		i++;
		if (!str[i])
			return (tmp1);
	}
	return (tmp1);
}
