#include "parsing.h"

static void	print_tuple(t_tuple4 tuple)
{
	if (tuple.w == POINT)
		printf("XYZ: %.2f,%.2f,%.2f\n", tuple.x, tuple.y, tuple.z);
	else if (tuple.w == VECTOR)
		printf("vector: %.2f,%.2f,%.2f\n", tuple.x, tuple.y, tuple.z);
}

void	print_obj2(t_object *obj)
{
	if (obj->type == o_light)
	{
		print_tuple(((t_light *)obj->data)->pos);
		printf("Lratio: %.2f\n", ((t_light *)obj->data)->bright);
	}
	if (obj->type == o_cone)
	{
		print_tuple(((t_cylin *)obj->data)->origin);
		print_tuple(((t_cylin *)obj->data)->normal);
		printf("Radius: %.2f\nheight: %.2f\n",
			((t_cylin *)obj->data)->radius, ((t_cylin *)obj->data)->height);
	}
	printf("RGB: %d,%d,%d\n\n",
		obj->mat.color.r, obj->mat.color.g, obj->mat.color.b);
}

void	print_obj1(t_object *obj)
{
	if (obj->type == o_cylin)
	{
		print_tuple(((t_cylin *)obj->data)->origin);
		print_tuple(((t_cylin *)obj->data)->normal);
		printf("Radius: %.2f\nheight: %.2f\n",
			((t_cylin *)obj->data)->radius, ((t_cylin *)obj->data)->height);
	}
	else if (obj->type == o_plane)
	{
		print_tuple(((t_plane *)obj->data)->origin);
		print_tuple(((t_plane *)obj->data)->normal);
	}
	else if (obj->type == o_sphere)
	{
		print_tuple(((t_sphere *)obj->data)->origin);
		printf("Radius: %.2f\n", 2 * ((t_sphere *)obj->data)->radius);
	}
	print_obj2(obj);
}

void	print_obj_main(t_scene *tmp)
{
	t_object	*obj;

	while (tmp && tmp->content)
	{
		obj = tmp->content;
		printf("-----------------------\n");
		if (obj->type == o_cylin)
			printf("cy :\n");
		else if (obj->type == o_light)
			printf("light :\n");
		else if (obj->type == o_plane)
			printf("pl :\n");
		else if (obj->type == o_sphere)
			printf("sp :\n");
		else if (obj->type == o_cone)
			printf("co :\n");
		print_obj1(obj);
		tmp = tmp->next;
	}
}

void	print_token(t_minirt *rt, t_scene *tmp)
{
	printf("\nminiRT struct\n\033[0;35m__________________________\033[0m"
		"\n\nfd: %d\n\n", rt->fd);
	if (rt->size)
		printf("R: %dx%d\n\n", rt->size->width, rt->size->height);
	if (rt->amb)
		printf("A: Lratio: %.2f\nRGB: %d,%d,%d\n\n",
			rt->amb->light, rt->amb->rgb.r, rt->amb->rgb.g, rt->amb->rgb.b);
	if (rt->cam)
		printf("C: XYZ: %.2f,%.2f,%.2f\nvector: %.2f,%.2f,%.2f\nFOV: %2.f\n\n",
			rt->cam->origin.x, rt->cam->origin.y, rt->cam->origin.z,
			rt->cam->target.x, rt->cam->target.y, rt->cam->target.z,
			rt->cam->fov);
	if (tmp)
		print_obj_main(tmp);
	printf("\nEND\n\033[0;35m__________________________\033[0m"
		"\n\n");
}
