
#include "so_long.h"

static int	get_map_width(char *map_path)
{
	int		fd;
	char	*line;
	int		w;

	w = 0;
	fd = open(map_path, O_RDONLY, 0);
	if (fd < 0)
		return (fd);
	get_next_line(fd, &line);
	w = ft_strlen(line);
	free(line);
	close(fd);
	return (w);
}

static int	get_map_height(char *map_path)
{
	int		fd;
	char	*line;
	int		h;

	h = 0;
	fd = open(map_path, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		h++;
		free(line);
		line = NULL;
	}
	if (line != NULL && ft_strlen(line) != 0)
		h++;
	free(line);
	close(fd);
	return (h);
}

int	helparse(int fd, t_data *data, int h, int w)
{
	int	i;

	i = -1;
	while (++i < h)
	{
		get_next_line(fd, &(data->map[i]));
		if (ft_strlen(data->map[i]) != (size_t)w)
		{
			data->h = i;
			return (1);
		}
		if (((i == h - 1 || i == 0) && check_char(data->map[i], "1"))
			|| (data->map[i][0] != '1' || data->map[i][w - 1] != '1'))
		{
			data->h = i;
			return (1);
		}
		if (check_char(data->map[i], "10PCE"))
		{
			data->h = i;
			return (1);
		}
	}
	return (0);
}

int	parse(char *map_path, t_data *data)
{
	int	fd;

	if (check_name(map_path))
		return (1);
	data->w = get_map_width(map_path);
	if (data->w < 0)
		return (1);
	data->h = get_map_height(map_path);
	fd = open(map_path, O_RDONLY, 0);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	data->map = (char **)malloc(sizeof(char *) * (data->h + 1));
	if (!(helparse(fd, data, data->h, data->w) == 0 && check_map(data) == 0))
	{
		write(1, "Error\n", 5);
		free_map_exit(data);
	}
	close(fd);
	return (0);
}
