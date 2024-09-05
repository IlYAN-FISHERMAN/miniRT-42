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
