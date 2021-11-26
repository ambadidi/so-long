/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 04:37:03 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/26 04:29:06 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_xppm(t_data *data, char *file, int index)
{
	int		fd;
	int		tab[5];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write (1, "Error\n", 6);
		free_map_exit(data);
	}
	close(fd);
	data->textuer[index].img = mlx_xpm_file_to_image(data->mlx, file,
			&data->textuer[index].img_width, &data->textuer[index].img_height);
	if (data->textuer[0].img == NULL)
	{
		exit(0);
		return (-1);
	}
	data->textuer[index].addr = (unsigned int *)mlx_get_data_addr(
			data->textuer[index].img, &tab[2], &tab[3], &tab[4]);
	if (data->textuer[index].addr == NULL)
	{
		exit(0);
		return (-1);
	}
	return (0);
}

void	texture(t_data *data)
{
	ft_texture(data, PLAYER, &data->p, 0);
	ft_texture(data, DOOR, &data->p, 1);
	ft_texture(data, FLOOR, &data->p, 2);
	ft_texture(data, WALL, &data->p, 3);
	ft_texture(data, FOOD, &data->p, 4);
}

int	ft_texture(t_data *data, char *line, unsigned int **adr, int index)
{
	int			j;

	if (*adr != NULL)
		return (-7);
	j = ft_xppm(data, line, index);
	if (j == -1)
		return (-9);
	return (0);
}

