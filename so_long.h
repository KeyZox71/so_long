/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:19:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/09 16:17:27 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MacroLibX/includes/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define TEXTURE_SIZE 64

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_window;

int		ft_move_character(int key, void *param);
int		key_close(int key, void *param);

int		ft_countline_fd(int fd);
char	**ft_read_map(char	*file_name);

int		ft_printmap(char **map, void *param);

#endif