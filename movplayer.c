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
	else
		(void) key;
}

void	helper(t_data *d, int key)
{
	
	if (key == ESC)
		ft_destroywindown(d);
	if (key == W_KEY &&  iswall(d, d->p_x, d->p_y - TS) ==0  && ft_printmv(d))
		d->p_y -= TS;
	if (key == S_KEY && iswall(d, d->p_x , d->p_y + TS ) == 0 && ft_printmv(d))
		d->p_y += TS;
	if (key == A_KEY &&  iswall(d, d->p_x - TS, d->p_y ) == 0 &&  ft_printmv(d))
			d->p_x -= TS;
	if (key == D_KEY &&  iswall(d, d->p_x  +  TS, d->p_y )  == 0 &&  ft_printmv(d))
		d->p_x -= TS;
	
	
		// helper2(d, key);
}
