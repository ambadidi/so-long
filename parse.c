/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:23:21 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:54:13 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char *map_path)
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

int	get_map_height(char *map_path)
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

int	check_char(char *s, const char *allowed)
{
	while (*s)
	{
		if (!ft_strchr(allowed, *s))
			return (1);
		s++;
	}
	return (0);
}

int	ft_strcmp(char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 > *s2)
			return ((unsigned char )*s1 - (unsigned char)*s2);
		if (*s1 < *s2)
			return ((unsigned char )*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	parse(char *map_path, t_data *data)
{
	int	fd;
	int	w;
	int	h;

	if (check_name(map_path))
		return (2);
	w = get_map_width(map_path);
	if (w < 0)
		return (1);
	h = get_map_height(map_path);
	data->w = w;
	data->h = h;
	fd = open(map_path, O_RDONLY, 0);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	data->map = (char **)malloc(sizeof(char *) * (h + 1));
	if (helparse(fd, data, h, w) == 1)
		return (1);
	close(fd);
	return (0);
}
