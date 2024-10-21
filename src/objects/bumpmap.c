#include "bumpmap.h"
#include "../exit_handler/exit_handler.h"

static void	error(char *msg, char *detail)
{
	if (detail)
		crash_exit(get_minirt(),
			(char *[]){"miniRT", "bumpmap", msg, 0}, detail);
	else
		crash_exit(get_minirt(),
			(char *[]){"miniRT", "bumpmap", 0}, msg);
}

static void	fill_data(t_bumpmap *bumpmap, char ***arr, size_t *i, size_t *j)
{
	while (*arr[1])
	{
		if (ft_isspace(**arr[1]))
		{
			arr[1]++;
			continue ;
		}
		if (*j >= bumpmap->width)
		{
			(*j) = 0;
			(*i)++;
			if (*i >= bumpmap->height)
				error("Invalid file format", "too many lines");
		}
		bumpmap->data[*i][*j] = byte_clamp(ft_atoi(*arr[1]));
		arr[1]++;
		(*j)++;
	}
}

static void	load_data(t_bumpmap *bumpmap, int fd)
{
	char	**arr[2];
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		arr[0] = ft_split(line, ' ');
		if (!arr[0])
			error("Failed to allocate memory", 0);
		arr[1] = arr[0];
		fill_data(bumpmap, arr, &i, &j);
		ft_free_tab(arr[0]);
		gfree(line);
		line = ft_get_next_line(fd);
	}
	if (i < bumpmap->height - 1 || j < bumpmap->width - 1)
		error("Invalid file format", "not enough data");
}

static void	load_meta(t_bumpmap *bumpmap, int fd)
{
	char	*line;
	char	**size;

	line = ft_get_next_line(fd);
	if (!line || ft_strcmp(line, "P2\n"))
		error("Invalid file format", "must be P2 normalized pgm file");
	gfree(line);
	line = ft_get_next_line(fd);
	if (!line)
		error("Failed to read file", 0);
	size = ft_split(line, ' ');
	if (!size)
		error("Failed to allocate memory", 0);
	if (ft_tablen(size) != 2)
		error("Invalid file format", "invalid size format");
	bumpmap->width = ft_atoi(size[0]);
	bumpmap->height = ft_atoi(size[1]);
	ft_free_tab(size);
	gfree(line);
	line = ft_get_next_line(fd);
	if (!line)
		error("Failed to read file", 0);
	if (ft_atoi(line) > 255 || ft_atoi(line) < 0)
		error("Invalid file format", "invalid max value");
	gfree(line);
}

t_bumpmap	*load_bumpmap(char *filename)
{
	t_bumpmap	*bumpmap;
	int			fd;
	size_t		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Failed to open file descriptor", filename);
	bumpmap = galloc(sizeof(t_bumpmap));
	if (!bumpmap)
		error("Failed to allocate memory", 0);
	load_meta(bumpmap, fd);
	i = 0;
	bumpmap->data = galloc(sizeof(t_byte *) * bumpmap->height);
	if (!bumpmap->data)
		error("Failed to allocate memory", 0);
	while (i < bumpmap->height)
	{
		bumpmap->data[i] = galloc(sizeof(t_byte) * bumpmap->width);
		if (!bumpmap->data[i++])
			error("Failed to allocate memory", 0);
	}
	load_data(bumpmap, fd);
	close(fd);
	return (bumpmap);
}
