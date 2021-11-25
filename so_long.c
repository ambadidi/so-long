/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:09:52 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:54:13 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_xppm(t_data *data, char *file, int index)
{
	int		fd;
	int		tab[6];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_destroywindown(data);
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

void	ft_img_pixel_put_2d( int x, int y, unsigned int color, t_data *data)
{
	unsigned int	*add;
	int				cord;

	add = (unsigned int *)mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	cord = (y * data->img.line_length / 4 + x);
	if (x < data->w * TS && x >= 0 && y >= 0 && y < data->h * TS)
		add[cord] = color;
}

void	draw_square(int x, int y, t_data *data, int index)
{
	int				i;
	int				j;
	int				c;
	unsigned int	*image;
	int				height;

	i = x;
	j = y;
	image = (unsigned int *) data->textuer[index].addr;
	height = 0;
	while (j < y + TS)
	{
		i = x;
		c = 0;
		while (i < x + TS)
		{
			ft_img_pixel_put_2d(i, j,
				image[((height * data->textuer[index].img_width) + c)], data);
			i++;
			c++;
		}
		j++;
		height++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	data.first = 0;
	data.mv = 0;
	if (parse(av[1], &data) >= 1)
		write (1, "map or extension error", 23);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.w * TS, data.h * TS,
			"######KHMIRA world!######");
	data.img.img = mlx_new_image(data.mlx, data.w * TS, data.h * TS);
	texture(&data);
	draw(&data);
	if (data.first != 1)
	{
		write (1, "map error, player missing or too many.", 39);
		ft_destroywindown(&data);
	}
	data.img.addr = (unsigned int *)mlx_get_data_addr(&data.img.img,
			&(data.img.bits_per_pixel),
			&(data.img.line_length), &(data.img.endian));
	mlx_help(&data);
	return (0);
}
