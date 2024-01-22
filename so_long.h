/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:19:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/21 15:42:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MacroLibX/includes/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define P_PNG "assets/player.png"
# define G_PNG "assets/ground.png"
# define E_PNG "assets/exit.png"
# define W_PNG "assets/wall.png"
# define C_PNG "assets/collectible.png"
# define T_SIZE 64

typedef struct s_coords
{
	int	x;
	int	y;
}		t_coords;

typedef struct s_img
{
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*ground;
}			t_img;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	char		**map;
	t_coords	*p_coords;
	t_coords	*e_coords;
	size_t		c_count;
	size_t		mov_count;
	t_img		*img;
}				t_window;

int		ft_key_event(int key, void *param);

void	ft_freemap(char	**map);
int		check_wall(char **map, t_coords *player);
size_t	ft_countline_fd(char *file_name);
char	**ft_read_map(char	*file_name);

char	ft_check_file(char	*file_name);
void	ft_exit(t_window *win);

void	ft_printmap(char **map, t_window *win);
void	ft_putimg(size_t x, size_t y, t_window *win, char c);
void	ft_check_map_error(char	**map);

void	ft_alloc_img(t_window *win);
char	ft_valid_file_ext(char *file_name);
void	ft_send_error(char *msg, char **map);
void	ft_check_map_error(char	**map);

#endif