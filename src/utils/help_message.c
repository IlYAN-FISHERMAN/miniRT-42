#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

void	help_message(t_minirt *minirt)
{
	printf("           _       _ ____ _____   "
		"             _     _      _ _            \n"
		"  _ __ ___ (_)_ __ (_|  _ |_   _|  "
		" __ _ _   _(_) __| | ___| (_)_ __   ___ \n"
		" | '_ ` _ \\| | '_ \\| | |_) || |   "
		" / _` | | | | |/ _` |/ _ | | | '_ \\ / _"
		" \\\n"
		" | | | | | | | | | | |  _ < | |   | (_"
		"| | |_| | | (_| |  __| | | | | |  __/\n"
		" |_| |_| |_|_|_| |_|_|_| \\_\\|_|    \\"
		"__, |\\__,_|_|\\__,_|\\___|_|_|_| |_|\\___|\n"
		"                                   |___"
		"/                                   \n");
	printf("\nUsage: ./miniRT [options] <scene.rt>\n\n");
	printf("		 ./miniRT [options] <scene.rt>\n\n");
	printf("Options:\n");
	printf("  -h               Display this help message\n");
	printf("  -res <X> <Y>     Set the window resolution\n");
	printf("  -save            Save the image to a BMP file\n");
	printf("  -scene <file>    Load the scene from an .rt file\n\n");
	printf("Examples:\n");
	printf("  ./miniRT -res 1920 1080 -scene scene.rt\n");
	printf("  ./miniRT -save -scene scene.rt\n");
	secure_exit(minirt);
}
