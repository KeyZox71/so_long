/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:19:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/28 18:24:35 by adjoly           ###   ########.fr       */
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
# include <limits.h>

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

typedef struct s_elemcount
{
	size_t	p_count;
	size_t	c_count;
	size_t	e_count;
}			t_elemcount;

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

// - Main -

// - Utils -

void	ft_freeimg(t_window *win);
size_t	ft_mapsize(char	**map);
void	ft_freemap(char	**map);
int		win_close(int event, void *param);
int		win_close(int event, void *param);
void	ft_exit(t_window *win);
void	ft_clear_alloc(t_window *win, char **map);
void	ft_destroy_display(t_window *win, char **map);

// - Get Map -

size_t	ft_filesize(char *file_name);
char	**ft_getmap(int fd, char **map_read, char *buf, char *tmp);
char	**ft_read_map(char *file_name, char **map_read);

// - Print Map -

void	ft_alloc_img(t_window *win);
void	ft_putimg(unsigned short x, unsigned short y, t_window *win, char c);
void	ft_printmap(char **map, t_window *win);

// - Move Character -

// move character
void	ft_printmov(t_window *win);
int		ft_key_event(int key, void *param);

// move up
void	ft_move_up(t_window *win);

// move down
void	ft_move_down(t_window *win);

// move left
void	ft_move_left(t_window *win);

// move right
void	ft_move_right(t_window *win);

// - Check Error -

// check file
char	ft_check_file(char	*file_name);
char	ft_valid_file_ext(char *file_name);
char	ft_is_empty(char **map);
char	ft_checknl(char	*filename);

//check map content
char	ft_check_reselement(t_elemcount *count);
char	ft_check_element(char **map, t_coords *p_coords, t_elemcount *count);
void	ft_check_map_content(char **map, t_coords *p_coords);

// check map error
char	ft_checkcol(char **map, char c, unsigned short col);
char	ft_is_rectangular(char **map);
char	ft_valid_char(char **map);
char	ft_checkline(char *map_line, char c);
void	ft_check_map_error(char	**map);

// check map state
void	ft_flood(int x, int y, char	**map);
char	ft_floodfill(char **map, t_coords *p_coords);
char	ft_is_closed(char **map);
void	ft_check_map_state(char **map, t_coords *p_coords);

// check map utils
void	ft_send_error(char *msg, char **map);
char	ft_check_charset(char c, char *charset);

#endif