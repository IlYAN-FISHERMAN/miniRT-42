#include "exit_handler.h"

void	free_mat(void *content)
{
	gfree(((t_define *)content)->name);
	gfree(content);
}
