
#include "so_long.h"

int	ft_strcount(char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_char(char *s, const char *allowed)
{
	while (*s)
	{
		if (!ft_strchr(allowed, *s))
			return (1);
		s++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	int	vars[4];

	ft_bzero(vars, sizeof(int) * 4);
	while (vars[0] < data->h)
	{
		if (ft_strchr(data->map[vars[0]], 'P'))
			vars[1] += ft_strcount(data->map[vars[0]], 'P');
		if (ft_strchr(data->map[vars[0]], 'C'))
			vars[2] += ft_strcount(data->map[vars[0]], 'C');
		if (ft_strchr(data->map[vars[0]], 'E'))
			vars[3] += ft_strcount(data->map[vars[0]], 'E');
		vars[0]++;
	}
	if (vars[1] != 1 || (vars[3] == 0 || vars[2] == 0))
		return (1);
	return (0);
}

int	check_name(char *av)
{
	if (ft_strcmp((av + (ft_strlen(av) - 4)), ".ber"))
		return (1);
	return (0);
}
