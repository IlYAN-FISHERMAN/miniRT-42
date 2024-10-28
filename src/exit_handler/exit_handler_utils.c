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
