/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:30:23 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:54:13 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	return (NULL);
}

int	check_name(char *av)
{
	if (ft_strcmp(&av[ft_strlen(av) - 4], ".ber"))
		return (1);
	return (0);
}

int	helparse(int fd, t_data *data, int h, int w)
{
	int	i;

	i = 0;
	while (i < h)
	{
		get_next_line(fd, &(data->map[i]));	

		if (ft_strlen(data->map[i]) != (size_t)w)
			return (1);
		if ((i == h - 1 || i == 0) && check_char(data->map[i], "1"))
			return (1);
		if (data->map[i][0] != '1' || data->map[i][w - 1] != '1')
			return (1);
		if (check_char(data->map[i], "10PCE"))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isfsh(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
