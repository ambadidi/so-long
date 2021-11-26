
#include "so_long.h"

static void	mlx_help(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_hook(data->mlx_win, BUTTONPRESS, (1L << 0), ft_movplayer, data);
	mlx_hook(data->mlx_win, DESTROYPRESS, 0L, ft_destroywindown, data);
	mlx_loop(data->mlx);
}

static void	help_main(t_data *data)
{
	if (data->first != 1)
	{
		write (1, "Error\n", 6);
		ft_destroywindown(data);
	}
	data->img.addr = (unsigned int *)mlx_get_data_addr(&data->img.img,
			&(data->img.bits_per_pixel),
			&(data->img.line_length), &(data->img.endian));
	mlx_help(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_bzero(&data, sizeof(data));
		data.first = 0;
		data.mv = 0;
		if ((parse(av[1], &data) == 1) || (data.w * TS > 3200 || data.h > 1760))
		{
			write (1, "Error\n", 6);
			return (1);
		}
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.w * TS, data.h * TS,
				"######KHMIRA world!######");
		data.img.img = mlx_new_image(data.mlx, data.w * TS, data.h * TS);
		texture(&data);
		draw(&data);
		help_main(&data);
	}
	else
		write (1, "Error\n", 6);
	return (0);
}
