/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:52:58 by abadidi           #+#    #+#             */
/*   Updated: 2021/11/25 01:33:01 by abadidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define BUTTONPRESS 2
# define DESTROYPRESS 17
# define TS 64
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0
# define ESC 53

#define  PLAYER "p.xpm"
#define  DOOR  "door.xpm"
#define  FLOOR  "grass.xpm"
#define  WALL  "bricks.xpm"
#define  FOOD "weed.xpm"


typedef	struct	s_img {
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}				t_img;

typedef	struct	s_data {
	void			*mlx;
	void			*mlx_win;
	t_img			textuer[6];
	t_img			img;
	int				w;
	int				h;
	char			**map;
	unsigned int	*p;
	int				first;
	int				p_x;
	int				p_y;
	int				mv;
}				t_data;





int		parse(char *map_path, t_data *data);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	draw_square(t_img *img, int x, int y, t_data *data, int index);
void	draw(t_data *data);
int		ft_movplayer(int key, void *d);
int		ft_isfsh(t_data *data);
void	drawwall(t_data *data, int i, int j, unsigned int	*v);
int		ft_texture(t_data *data, char *line, unsigned int **adr, int index);
char	*ft_strchr(const char *s, int c);
int		ft_destroywindown(t_data *data);
int		check_name(char *av);
int		helparse(int fd, t_data *data, int h, int w);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		check_char(char *s, const char *allowed);
int		ft_strcmp(char *s1, const char *s2);
void	helper(t_data *d, int key);
int		ft_movplayer(int key, void *d);
int		ft_printmv(t_data *data);
int		iswall(t_data *data, int x, int y);

#endif