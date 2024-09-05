#include "../miniRT.h"
#include "../objects/cylinder.h"

void	print_obj1(t_plane *pl, t_sphere *sp, t_cylin *cy)
{
	if (cy)
		printf("cy: XYZ: %.2f,%.2f,%.2f\nvector: %.2f,%.2f,%.2f \
		\nDiameter: %.2f\nheight: %.2f\nRGB: %d,%d,%d\n\n",
			cy->origin.x, cy->origin.y, cy->origin.z, cy->normal.x,
			cy->normal.y, cy->normal.z, cy->diam, cy->height,
			cy->rgb.r, cy->rgb.g, cy->rgb.b);
	else if (pl)
		printf("pl: XYZ: %.2f,%.2f,%.2f\n"\
			"vector: %.2f,%.2f,%.2f\nRGB: %d,%d,%d\n\n", \
			pl->origin.x, pl->origin.y, pl->origin.z,
			pl->normal.x, pl->normal.y,
			pl->normal.z, pl->color.r, pl->color.g, pl->color.b);
	else if (sp)
		printf("sp: XYZ: %.2f,%.2f,%.2f\nDiameter: %.2f\nRGB: %d,%d,%d\n\n", \
			sp->origin.x, sp->origin.y, sp->origin.z, sp->radius,
			sp->color.r, sp->color.g, sp->color.b);
}

void	print_light(t_light *lig)
{
	if (lig)
		printf("L: XYZ: %.2f,%.2f,%.2f\nLratio: %.2f\nRGB: %d,%d,%d\n\n",
			lig->pos.x, lig->pos.y, lig->pos.z, lig->bright,
			lig->rgb.r, lig->rgb.g, lig->rgb.b);
}

void	print_obj_main(t_scene *tmp)
{
	t_object	*obj;

	while (tmp && tmp->content)
	{
		obj = tmp->content;
		if (obj->type == o_light)
			print_light(obj->data);
		else if (obj->type == o_cylin)
			print_obj1(NULL, NULL, obj->data);
		else if (obj->type == o_plane)
			print_obj1(obj->data, NULL, NULL);
		else if (obj->type == o_sphere)
			print_obj1(NULL, obj->data, NULL);
		tmp = tmp->next;
	}
}

void	print_token(t_minirt *rt, t_scene *tmp)
{
	printf("\nminiRT struct\n-----------\n\nfd: %d\n\n", rt->fd);
	if (rt->size)
		printf("R: %.0fx%.0f\n\n", rt->size->height, rt->size->width);
	if (rt->amb)
		printf("A: Lratio: %.2f\nRGB: %d,%d,%d\n\n",
			rt->amb->light, rt->amb->rgb.r, rt->amb->rgb.g, rt->amb->rgb.b);
	if (rt->cam)
		printf("C: XYZ: %.2f,%.2f,%.2f\nvector: %.2f,%.2f,%.2f\nFOV: %2.f\n\n",
			rt->cam->origin.x, rt->cam->origin.y, rt->cam->origin.z,
			rt->cam->forward.x, rt->cam->forward.y, rt->cam->forward.z,
			rt->cam->fov);
	if (tmp)
		print_obj_main(tmp);
}
