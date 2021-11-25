/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 04:37:03 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 05:16:46 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture(t_data *data)
{
	ft_texture(data, PLAYER, &data->p, 0);
	ft_texture(data, DOOR, &data->p, 1);
	ft_texture(data, FLOOR, &data->p, 2);
	ft_texture(data, WALL, &data->p, 3);
	ft_texture(data, FOOD, &data->p, 4);
}

void	mlx_help(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_hook(data->mlx_win, BUTTONPRESS, (1L << 0), ft_movplayer, data);
	mlx_hook(data->mlx_win, DESTROYPRESS, 0L, ft_destroywindown, data);
	mlx_loop(data->mlx);
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
