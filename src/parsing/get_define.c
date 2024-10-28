#include "ft_linked_list.h"
#include "ft_memory.h"
#include "ft_string.h"
#include "parsing.h"

int	is_define(char *str, t_mats *iter)
{
	t_define	*tmp;

	while (iter)
	{
		tmp = iter->content;
		if (!ft_strcmp(str, tmp->name))
			return (1);
		iter = iter->next;
	}
	return (0);
}

void	check_bumpmap_error(char *str, t_minirt *minirt)
{
	if (!ft_strrchr(str, '.') || ft_strcmp(ft_strrchr(str, '.'), ".pgm"))
		crash_exit(minirt,
			(char *[]){"miniRT", "Bumpmap", NULL}, "Need *.pgm file");
	if (access(str, F_OK) || access(str, R_OK))
		crash_exit(minirt, (char *[]){"miniRT", "Bumpmap"
			"No such file or directory", NULL}, str);
}

void	check_define_range(char **str, t_minirt *minirt)
{
	if (ft_atof(str[2]) < 0.0 || ft_atof(str[2]) > 1.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad diffuse range\n[diffuse: >0.0/<1.0]", NULL}, str[2]);
	if (ft_atof(str[3]) < 0.0 || ft_atof(str[3]) > 1.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad specular range\n[specular: >0.0/<1.0]", NULL}, str[3]);
	if (ft_atof(str[4]) < 0.0 || ft_atof(str[4]) > 1000.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Define: Bad "
			"shininess range\n[shininess: >0.0/<1000.0]", NULL}, str[4]);
	if (ft_atof(str[5]) < 0.0 || ft_atof(str[5]) > 1.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Define: Bad "
			"reflect range\n[reflectivity: >0.0/<1.0]", NULL}, str[5]);
	if (ft_atof(str[6]) < 0.0 || ft_atof(str[6]) > 1.0)
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Define: Bad "
			"transp range\n[transparency: >0.0/<1.0]", NULL}, str[6]);
	if (ft_atof(str[7]) < 0.0 || ft_atof(str[7]) > 2.5)
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Define: Bad "
			"refractive index range\n[refractive Index: >0.0/<2.5]", \
			NULL}, str[7]);
}

void	check_define_format(char **str, t_minirt *minirt)
{
	if (ft_strlen_tab(str) < 8 || ft_strlen_tab(str) > 9)
		crash_exit(minirt, (char *[]){"miniRT", "parsing: Define: Bad"
			" number of arg", NULL}, "\ndefine [name] [diff: 0.0] [spec: 0.0]"
			" [shin: 0.0] [reflect: 0.0] [transp: 0.0] [refract_idx: 0.0] "
			"[bumpmap: example.pgm][optional]\n");
	if (!only_double(str[2]) && !only_digit(str[2]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad diffuse format\n[diffuse: 0.0]", NULL}, str[2]);
	if (!only_double(str[3]) && !only_digit(str[3]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad specular format\n[specular: 0.0]", NULL}, str[3]);
	if (!only_double(str[4]) && !only_digit(str[4]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad shininess format\n[shininess: 0.0]", NULL}, str[4]);
	if (!only_double(str[5]) && !only_digit(str[5]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad reflect format\n[reflectivity: 0.0]", NULL}, str[5]);
	if (!only_double(str[6]) && !only_digit(str[6]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing",
			"Define: Bad transp format\n[transparency: 0.0]", NULL}, str[6]);
	if (!only_double(str[7]) && !only_digit(str[7]))
		crash_exit(minirt, (char *[]){"miniRT", "parsing", "Define: Bad"
			" refractive index format\n[refractive Index: 0.0]", NULL}, str[7]);
	if (str[8])
		check_bumpmap_error(str[8], minirt);
}

void	get_define(char **str, t_minirt **minirt)
{
	t_define	*define;

	check_define_format(str, *minirt);
	check_define_range(str, *minirt);
	define = ft_calloc(1, sizeof(t_define));
	if (!define)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	define->name = ft_strdup(str[1]);
	if (!define->name)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	define->mat = (t_mat){.color = color(0, 0, 0), .diff = ft_atof(str[2]), \
	.spec = ft_atof(str[3]), .shin = ft_atof(str[4]), \
	.reflect = ft_atof(str[5]), .transp = ft_atof(str[6]), \
		.refract_idx = ft_atof(str[7]), .bumpmap = NULL};
	if (str[8])
		define->mat.bumpmap = load_bumpmap(str[8]);
	ft_lstnew_back(&(*minirt)->mat, define);
}
