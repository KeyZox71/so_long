/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/09 16:08:20 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stddef.h>

int	ft_putimg(int x, int y, void *param, char *file_path)
{
	t_window	*win;

	win = (t_window *)param;

	win->img = mlx_png_file_to_image(win->mlx, file_path, &x, &y);
	mlx_put_image_to_window(win->mlx, win->win, win->img, x * TEXTURE_SIZE, y * TEXTURE_SIZE);
	return (0);
}

int	ft_printmap(char **map, void *param)
{
	size_t		x;
	size_t		y;
	t_window	*win;

	y = 0;
	win = (t_window *)param;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_putstr_fd("??", 1);
			if (map[y][x] == '1')
				ft_putimg(x, y, param, "assets/wall.png");
			else if (map[y][x] == '0')
				ft_putimg(x, y, param, "assets/ground.png");
			else if (map[y][x] == 'C')
				ft_putimg(x, y, param, "assets/obj.png");
			else if (map[y][x] == 'E')
				ft_putimg(x, y, param, "assets/exit.png");
			else if (map[y][x] == 'P')
				ft_putimg(x, y, param, "assets/player.png");
			x++;
		}
		y++;
	}
	return (0);
}
