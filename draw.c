/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 07:09:54 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:54:13 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_draw(t_data *data, int i, int x, int y)
{
	int	j;

	j = -1;
	while (++j < data->w)
	{
		if (data->map[i][j] == 'P')
		{
			if (data->first == 0)
			{
				data->p_x = j * TS;
				data->p_y = i * TS;
				data->first = 1;
				data->map[i][j] = '0';
			}
		}
		else if (data->map[i][j] == '1')
			draw_square(x, y, data, 3);
		else if (data->map[i][j] == '0')
			draw_square(x, y, data, 2);
		else if (data->map[i][j] == 'C')
			draw_square(x, y, data, 4);
		else if (data->map[i][j] == 'E')
			draw_square(x, y, data, 1);
		x += TS;
	}
}

void	draw(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < data->h)
	{
		x = 0;
		help_draw(data, i, x, y);
		y += TS;
		i++;
	}
	draw_square(data->p_x, data->p_y, data, 0);
}
