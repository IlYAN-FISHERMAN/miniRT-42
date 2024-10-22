#include "parsing.h"

void	pars_map(t_minirt **minirt)
{
	char	**str;
	char	*gnl;

	printf("fd:%d\n", (*minirt)->fd);
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
	if (check_standare_shape(*minirt) && !(*minirt)->size)
		get_size_default(minirt);
}
