#include "parsing.h"

int	only_digit(char *str)
{
	int		nb;
	char	*tmp;

	nb = ft_atoi(str);
	tmp = ft_itoa(nb);
	if (!tmp)
		return (0);
	if (ft_strcmp(str, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	only_float(char *str)
{
	int		i;

	i = -1;
	if (!str || str[0] == '.')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i] && str[i] != '.')
		if (!ft_isdigit(str[i]) || !str[i + 1])
			return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	only_digit_xyz(char *split, t_minirt *minirt)
{
	int		j;
	char	**str;

	if (!ft_strchr(split, ','))
		return (0);
	j = -1;
	str = ft_split(split, ',');
	if (!str)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	while (str[++j])
	{
		if (!only_digit(str[j]) || j >= 3)
		{
			ft_free_tab(str);
			return (0);
		}
	}
	ft_free_tab(str);
	if (j <= 2)
		return (0);
	return (1);
}

int	only_float_xyz(char *split, t_minirt *minirt)
{
	int		j;
	char	**str;

	j = -1;
	if (!ft_strchr(split, ','))
		return (0);
	str = ft_split(split, ',');
	if (!str)
		crash_exit(minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	while (str[++j])
	{
		if (!only_float(str[j]) && !only_digit(str[j]))
		{
			ft_free_tab(str);
			return (0);
		}
	}
	if (j <= 2 || j > 3)
		return (0);
	ft_free_tab(str);
	return (1);
}
