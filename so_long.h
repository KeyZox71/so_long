/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:19:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/13 17:13:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MacroLibX/includes/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define T_SIZE 64
# define P_PNG "assets/player.png"
# define G_PNG "assets/ground.png"
# define E_PNG "assets/exit.png"
# define W_PNG "assets/wall.png"
# define C_PNG "assets/collectible.png"

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**map;
	t_coords	*p_coords;
	size_t		*c_count;
	size_t		*mov_count;
}					t_window;

int		ft_key_event(int key, void *param);

int		check_wall(char **map, t_coords *player);
int		ft_countline_fd(int fd);
char	**ft_read_map(char	*file_name);

void	ft_printmap(char **map, t_window *win);
void	ft_putimg(size_t x, size_t y, t_window *win, char *file_path);

#endif