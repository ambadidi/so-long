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

void    draw(t_data *data)
{
    int i;
    int j;
    int x;
    int y;


    i = 0;
    y = 0;	
	// printf("[%d  %d]\n", data->w , data->h );
    while (i < data->h)
	{
        x = 0;
        j = 0;

		while (j < data->w)
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
			else if (data->map[i][j] ==  '1')
				draw_square(&data->img, x, y, data, 3);
			else if (data->map[i][j] ==  '0')
				draw_square(&data->img, x , y, data, 2);
			else if (data->map[i][j] ==  'C')
				draw_square(&data->img, x , y, data, 4);
            else if (data->map[i][j] ==  'E')
				draw_square(&data->img, x , y, data, 1);
			x+= TS;
            j++;
		}

		y+= TS;			
        i++;
	}
	printf("{%d %d}\n", data->p_x, data->p_y);
		draw_square(&data->img,  data->p_x   , data->p_y, data,0);

	//drawwall(data, data->p_y, data->p_x, data->p);
}
