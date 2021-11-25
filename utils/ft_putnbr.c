/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 03:46:59 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 03:54:40 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	my_nb;

	if (n < 0)
	{
		ft_putchar('-');
		my_nb = -n;
	}
	else
		my_nb = n;
	if (my_nb / 10)
		ft_putnbr(my_nb / 10);
	ft_putchar(my_nb % 10 + '0');
}