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
	{
		printf("can't open [%s]\n", file);
		ft_destroywindown(data);
	}
	close(fd);
   data->textuer[index].img  = mlx_xpm_file_to_image(data->mlx, file, &data->textuer[index].img_width  ,&data->textuer[index].img_height);
	// if (data->textuer[0].img == NULL || data->textuer[0].img_width != TS || data->textuer->img_height !=  TS)
	if (data->textuer[0].img == NULL)
	{
		printf(" img   %d  \n",(int )data->textuer[0].img_width );
		exit(0);
		return (-1);
	}
	data->textuer[index].addr = (unsigned int*)mlx_get_data_addr(data->textuer[index].img
			, &tab[2], &tab[3], &tab[4]);
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

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	if (x < 0 || x > data->w || y < 0 || y > data->h)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawwall(t_data *data, int i, int j, unsigned int	*v)
{
	int	y;
	int	x;
	int	s;

	y = j;
	x = -1;
	s = 1;
	while (++x <  TS && i < data->w)
	{
		j = y - 1;
		s = -1;
		i++;
		while (++j < y + TS  && j < data->h - 1)
			if (x < TS && ++s < TS)
				if ((unsigned int)v[(s * TS) + x] != (unsigned int)4278190080)
					my_mlx_pixel_put(data, i, j, v[(s * 64) + x]);
	}
}

void	ft_img_pixel_put_2d(t_img *img, int x, int y,unsigned int color, t_data *data)
{
	unsigned int *add;
	int cord;

	add = (unsigned int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	cord = (y * img->line_length / 4 + x);
	if (x < data->w  * TS && x >= 0 && y >= 0 &&  y  < data->h  * TS)
		add[cord] = color;
}


void	draw_square(t_img *img,int x, int y, t_data *data, int index)
{
	int i;
	int j;

	int target_x = x + TS;
	int target_y = y + TS;
	i = x;
	j = y;
	int c = 0;
	unsigned int *image = (unsigned int *) data->textuer[index].addr;
	int height = 0;
	while (j <  target_y)
	{
		i = x;
		c = 0;
		while (i < target_x)
		{
			unsigned int color = image[((height * data->textuer[index].img_width) + c)];
			ft_img_pixel_put_2d(img, i, j, color, data);
			i++;
			c++;
		}
		j++;
		height++;
	}
}

int	ft_destroywindown(t_data	*data)
{
	int	i;
	printf("{{{{}}}}===>%s\n", data->map[0]);
	i = 0;
	if (data->map != NULL)
		while (i < data->h)
			free(data->map[i++]);
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data		data;

	data.first = 0;
	data.mv = 0;
	if(parse(av[1], &data) >= 1)
	{
		write (1, "map or extension error", 23);
		// ft_destroywindown(&data);
	}
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.w * TS, data.h * TS, "######KHMIRA world!######");
	data.img.img = mlx_new_image(data.mlx, data.w * TS, data.h * TS);
	ft_texture(&data, PLAYER , &data.p,0 );
	ft_texture(&data, DOOR, &data.p,1);
	ft_texture(&data,  FLOOR, &data.p,2);
	ft_texture(&data, WALL, &data.p,3);
	ft_texture(&data,  FOOD, &data.p,4);
	draw(&data);
	if (data.first != 1)
	{
		printf("nb players = %d\n", data.first);
		write (1, "map error, player missing or too many.", 39);
		ft_destroywindown(&data);
	}
	data.img.addr = (unsigned int*)mlx_get_data_addr(&data.img.img, &(data.img.bits_per_pixel), &(data.img.line_length), &(data.img.endian));
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img, 0, 0);
	mlx_hook(data.mlx_win, BUTTONPRESS, (1L << 0), ft_movplayer, &data);
	mlx_hook(data.mlx_win, DESTROYPRESS, 0L, ft_destroywindown, &data);
	mlx_loop(data.mlx);
	return (0);
}