#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

t_scene	*get_scene_struct(t_minirt **minirt)
{
	t_scene	*scene;

	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	scene->content = ft_calloc(1, sizeof(t_object));
	if (!scene->content)
		crash_exit(*minirt,
			(char *[]){"miniRT", "parsing", NULL}, "Malloc failed");
	return (scene);
}

void	get_obj(char **str, t_minirt **minirt)
{
	if (!ft_strcmp(str[0], "pl"))
		get_pl(str, minirt);
	else if (!ft_strcmp(str[0], "cy"))
		get_cy(str, minirt);
	else if (!ft_strcmp(str[0], "sp"))
		get_sp(str, minirt);
}
