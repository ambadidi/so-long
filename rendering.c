#include "so_long.h"

static void	ft_img_pixel_put_2d( int x, int y, unsigned int color, t_data *data)
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

static void	draw_square(int x, int y, t_data *data, int index)
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

static void	help_draw(t_data *data, int i, int x, int y)
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
