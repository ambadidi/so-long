/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movplayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 06:27:15 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:54:13 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	helper2(t_data *data, int key)
{
	if (((data->p_x - TS) >= 0 && (data->p_x + TS) <= data->w * TS)
		&& iswall(data, data->p_x + TS, data->p_y) == 0)
	{
		if (key == D_KEY && ft_printmv(data))
				data->p_x += TS;
	}
}

void	helper(t_data *d, int key)
{
	if (key == ESC)
		ft_destroywindown(d);
	if (key == W_KEY && iswall(d, d->p_x, d->p_y - TS) == 0 && ft_printmv(d))
		d->p_y -= TS;
	if (key == S_KEY && iswall(d, d->p_x, d->p_y + TS) == 0 && ft_printmv(d))
		d->p_y += TS;
	if (key == A_KEY && iswall(d, d->p_x - TS, d->p_y) == 0 && ft_printmv(d))
			d->p_x -= TS;
	if (key == D_KEY && iswall(d, d->p_x + TS, d->p_y) == 0 && ft_printmv(d))
		d->p_x -= TS;
}

int	ft_destroywindown(t_data	*data)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(data->mlx, data->textuer[i].img);
	mlx_destroy_image(data->mlx, data->img.img);
	free_map_exit(data);
	return (0);
}

void	free_map_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (i < data->h)
		{
			if (data->map[i] != NULL)
				free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	exit(1);
}
