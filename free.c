
#include "so_long.h"

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
