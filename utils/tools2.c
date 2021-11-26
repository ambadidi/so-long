

#include "../so_long.h"

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*dest;

	dest = str;
	while (n--)
	{
		*dest = (unsigned char)c;
		dest++;
	}
	return (str);
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
	return (NULL);
}

int	ft_strcmp(char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 > *s2)
			return ((unsigned char )*s1 - (unsigned char)*s2);
		if (*s1 < *s2)
			return ((unsigned char )*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

