/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/11 18:19:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stddef.h>

void	ft_putimg(int x, int y, t_window *win, char *file_path)
{
	int	img_x;
	int	img_y;

	img_x = 0;
	img_y = 0;
	if (file_path[7] == 'p')
	{
		win->player_y = ft_calloc(sizeof(int), 1);
		win->player_y = &y;
		win->player_x = ft_calloc(sizeof(int), 1);
		win->player_x = &x;
	}
	ft_putstr_fd(file_path, 1);
	ft_putchar_fd('\n', 1);
	win->img = mlx_png_file_to_image(win->mlx, file_path, &img_x, &img_y);
	mlx_put_image_to_window(win->mlx, win->win, win->img, x * img_x, y * img_y);
}

void	ft_printmap(char **map, t_window *win)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_putimg(x, y, win, "assets/wall.png");
			else if (map[y][x] == '0')
				ft_putimg(x, y, win, "assets/ground.png");
			else if (map[y][x] == 'C')
				ft_putimg(x, y, win, "assets/obj.png");
			else if (map[y][x] == 'E')
				ft_putimg(x, y, win, "assets/exit.png");
			else if (map[y][x] == 'P')
				ft_putimg(x, y, win, "assets/player.png");
			x++;
		}
		y++;
	}
}
