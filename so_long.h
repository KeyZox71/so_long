/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:19:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/10 14:50:43 by adjoly           ###   ########.fr       */
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

# define TEXTURE_SIZE 64

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*player_x;
	int		*player_y;
}					t_window;

int		ft_move_character(int key, void *param);
int		key_close(int key, void *param);

int		ft_countline_fd(int fd);
char	**ft_read_map(char	*file_name);

void	ft_printmap(char **map, t_window *win);
void	ft_putimg(int x, int y, t_window *win, char *file_path);

#endif