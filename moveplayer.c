/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:55:45 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:54:13 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	iswall(t_data *data, int x, int y)
{
	int		new_x;
	int		new_y;

	new_x = x / TS;
	new_y = y / TS;
	if (new_x < 0 || new_y < 0)
		return (1);
	if (new_x > TS * data->w || new_y > TS * data->h)
		return (1);
	if (data->map[new_y][new_x] == '1'
		|| (data->map[new_y][new_x] == 'E' && !ft_isfsh(data)))
		return (1);
	return (0);
}

int	iscollect(t_data *data, int x, int y)
{
	int		new_x;
	int		new_y;
	int		new_xt;
	int		new_yt;

	new_x = x / TS;
	new_y = y / TS;
	new_xt = (x + TS / 2) / TS;
	new_yt = (y + TS / 2) / TS;
	if ((new_x >= 0 && new_x <= data->w && new_y >= 0
			&& new_y <= data->h) && (data->map[new_y][new_x] == 'C'
		|| data->map[new_y][new_xt] == 'C' ||
		data->map[new_yt][new_x] == 'C' ||
		data->map[new_yt][new_xt] == 'C'))
		return (1);
	return (0);
}

void	collect(t_data *data, int x, int y)
{
	int		new_x;
	int		new_y;

	new_x = x / TS;
	new_y = y / TS;
	if (new_x > 0 && new_x < data->w && new_y > 0
		&& new_y < data->h && data->map[new_y][new_x] == 'E' && ft_isfsh(data))
	{
		write(1, "Exit\n", 5);
		exit(0);
	}
	if (iscollect(data, x, y) == 1)
	{
		write(1, "Collect\n", 8);
		data->map[new_y][new_x] = '0';
	}
}

void	move_help(int key, t_data *data)
{
	if (key == ESC)
		ft_destroywindown(data);
	if (key == W_KEY && iswall(data, data->p_x,
			data->p_y - TS) == 0 && ft_printmv(data))
		data->p_y -= TS;
	if (key == S_KEY && iswall(data, data->p_x,
			data->p_y + TS) == 0 && ft_printmv(data))
		data->p_y += TS;
	if (key == A_KEY && iswall(data, data->p_x - TS,
			data->p_y) == 0 && ft_printmv(data))
			data->p_x -= TS;
	if (key == D_KEY && iswall(data, data->p_x + TS, data->p_y) == 0
		&& ft_printmv(data))
		data->p_x += TS;
}

int	ft_movplayer(int key, void *d)
{
	t_data		*data;

	data = (t_data *)d;
	move_help(key, data);
	collect(data, data->p_x, data->p_y);
	mlx_clear_window(data->mlx, data->mlx_win);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, data->w * TS, data->h * TS);
	draw(data);
	data->img.addr = (unsigned int *)mlx_get_data_addr(&data->img.img,
			&(data->img.bits_per_pixel), &(data->img.line_length),
			&(data->img.endian));
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.img, 0, 0);
	return (1);
}
