#include "../miniRT.h"
#include "../exit_handler/exit_handler.h"

static void	print_usage(void)
{
	printf("\nUsage: ./miniRT <scene.rt>\n       ./miniRT [options]\n\n\
Options:\n  -h                 Display this help message\n  -r -random         \
Create a random <scene.rt>\n  <scene.rt> <file>  Load the scene from an \
.rt file\n\nExamples:\n  ./miniRT scene.rt\n  ./miniRT -r\n\nExemple of a .rt \
file:\n");
}

static void	print_map_ex(void)
{
	printf("───────┬───────────────────────────────────────────────────────────"
		"──────────────────────────┬\n       │ File: exemple.rt                "
		"                                                    │\n───────┼───────"
		"──────────────────────────────────────────────────────────────────────"
		"────────│\n   1   │ R    1000          1000                           "
		"                                  │\n   2   │ A     0.4  255,255,255  "
		"                                                            │\n   3   "
		"│ C 0,0,-30 0,0,1 80                                                  "
		"                │\n   4   │ L    0.0,2.2,2.1     1.0     81,9,134     "
		"                                          │\n   5   │                 "
		"                                                                    │"
		"\n   6   │ define   new_mat   1.0 0.3 0.3 1.0 1.0 0.4 bumpmap.pgm     "
		"                         │\n   7   │                                  "
		"                                                   │\n   8   │ pl 0,-1"
		"5,0 0,1,0 255,255,255                                                 "
		"       │\n   9   │ co    10.2,7.1,2.10     0.0,1.0,1.0     10.9     4."
		"0     185,199,159 plastic        │\n  10   │ co    -9.9,7.0,9.0     -1"
		".0,0.0,1.0     5.3     9.4     51,178,38   new_mat         │\n  11   │"
		" co    -4.5,9.9,9.0     -1.0,1.0,-1.0     12.6     20.3     4,202,159 "
		"metal          │\n  12   │ sp    -1.9,-2.0,7.0     7.0     170,172,171"
		"                                         │\n  13   │ sp    -10.1,-7.1,"
		"-9.6     8.0     230,68,153 mirror                                 │\n"
		"───────┴──────────────────────────────────────────────────────────────"
		"───────────────────────┴\n\n\nHow to create my own .rt file:\n");
}

static void	print_def(void)
{
	printf("1. The resolution (R) defines the width and height of the render wi"
		"ndow.\n   Example: 'R 1920 1080' for a 1920x1080 resolution.\n2. The a"
		"mbient light (A) sets the intensity and color.\n   Example: 'A 0.2 25"
		"5,255,255' for a 20%% intensity with white light.\n3. The camera (C) "
		"sets its position, orientation, and field of view.\n   Example: 'C 0,"
		"0,0 0,0,1 60' for a camera at (0,0,0) looking along the Z-axis with a"
		" 60-degree FOV.\n4. The light (L) defines the light source position, "
		"intensity, and color.\n   Example: 'L 10,10,10 1.0 255,255,255' for a"
		" light at (10,10,10) with full intensity and white light.\n\n5. The sph"
		"eres (sp) describe their position, radius, and color.\n   Example: 's"
		"p 0,0,20 10 255,0,0' for a red sphere at (0,0,20) with a radius of 10"
		" units\n6. Planes (pl) define an infinite plane with a position, n"
		"ormal vector, and color.\n   Example: 'pl 0,1,0 0,1,0 0,255,0' for a "
		"green plane at Y=0, normal pointing upwards.\n7. Cylinders (cy) are d"
		"efined by a position, orientation, diameter, height, and color.\n   E"
		"xample: 'cy 0,0,0 0,1,0 5 20 255,255,0' for a yellow cylinder at (0,0"
		",0) with diameter 5, height 20, along Y axis.\n8. Cone (co) are d"
		"efined by a position, orientation, diameter, height, and color.\n   E"
		"xample: 'co 0,0,0 0,1,0 5 20 255,255,0' for a yellow cone at (0,0"
		",0) with diameter 5, height 20, along Y axis.\n\n9. You can add commen"
		"ts in you"
		"r .rt file by starting the line with '#'.\n    Example:\n# This is a "
		"comment and will be ignored by the parser.\n\n10. Materials can be de"
		"fined with the 'define' keyword, allowing you to create your own");
}

static void	print_def2(void)
{
	printf(" materials.\n    Example: 'define new_material 1.0 0.3 0.1 0.4 bump"
		"map.pgm'\n    This defines a new material with the following parameter"
		"s:\n      - Diffuse reflection (1.0)\n      - Specular reflection (0.3"
		")\n      - Ambient reflection (0.1)\n      - Shininess (0.4)\n      - "
		"A bump map texture file ('bumpmap.pgm') for surface detail.\n\n11. Ass"
		"igning materials to objects:\n    Once a material is defined, you can "
		"apply it to an object using the material name.\n    Example: 'sp 0,0,2"
		"0 10 255,255,255 new_material' will apply 'new_material' to the sphere"
		".\n\n12. Bump mapping allows you to add surface texture to your object"
		"s. You can specify a bump map file for each material.\n    Example: 'd"
		"efine mat_with_bump 1.0 0.3 0.1 0.4 0.2 1.5 bump_texture.pgm'\n    Thi"
		"s uses the 'bump_texture.pgm' file to add bumps to the surface of obje"
		"cts using this material.\n\n13. Valid bump mapping textures are in for"
		"mat PGM P2 and cannot contain comments.\n    You easily can generate y"
		"our own by using our builtin script in `scripts/imt2pgm.sh`.\n    Note"
		" that this script requires imagemagick in order to work properly.\n\n");
}

void	help_message(t_minirt *minirt)
{
	printf("            _       _ ____ _____   "
		"            _     _      _ _            \n"
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
	print_usage();
	print_map_ex();
	print_def();
	print_def2();
	printf("14. You can add default material like:\n	- metal\n	- wood\n"
		"	- plastic\n	- mirror\n	- glass\n	- bricks\n	- checkerboard\n"
		"	- mat\n\nFor more advanced scenes, you can combine different mat"
		"erials, bump maps, and objects to create complex environments.\n");
	secure_exit(minirt);
}
