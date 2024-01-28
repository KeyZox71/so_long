/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/27 15:43:36 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <limits.h>

void	ft_alloc_img(t_window *win)
{
	int		img_x;
	int		img_y;

	img_y = 0;
	img_x = 0;
	win->img->collectible = mlx_png_file_to_image(win->mlx,
			C_PNG, &img_x, &img_y);
	win->img->exit = mlx_png_file_to_image(win->mlx, E_PNG, &img_x, &img_y);
	win->img->ground = mlx_png_file_to_image(win->mlx, G_PNG, &img_x, &img_y);
	win->img->player = mlx_png_file_to_image(win->mlx, P_PNG, &img_x, &img_y);
	win->img->wall = mlx_png_file_to_image(win->mlx, W_PNG, &img_x, &img_y);
}

void	ft_putimg(unsigned short x, unsigned short y, t_window *win, char c)
{
	if (c == 'E')
	{
		win->e_coords->x = x;
		win->e_coords->y = y;
		mlx_put_image_to_window(win->mlx, win->win,
			win->img->exit, x * T_SIZE, y * T_SIZE);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(win->mlx, win->win,
			win->img->collectible, x * T_SIZE, y * T_SIZE);
		win->c_count++;
	}
	else if (c == '0')
		mlx_put_image_to_window(win->mlx, win->win,
			win->img->ground, x * T_SIZE, y * T_SIZE);
	else if (c == 'P')
	{
		win->p_coords->y = y;
		win->p_coords->x = x;
		mlx_put_image_to_window(win->mlx, win->win,
			win->img->player, x * T_SIZE, y * T_SIZE);
	}
}

void	ft_printmap(char **map, t_window *win)
{
	unsigned short	x;
	unsigned short	y;

	y = 0;
	win->c_count = 0;
	while (map[y] != NULL && y < USHRT_MAX)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(win->mlx, win->win,
					win->img->wall, x * T_SIZE, y * T_SIZE);
			else if (map[y][x] == '0')
				ft_putimg(x, y, win, map[y][x]);
			else if (map[y][x] == 'C')
				ft_putimg(x, y, win, map[y][x]);
			else if (map[y][x] == 'E')
				ft_putimg(x, y, win, map[y][x]);
			else if (map[y][x] == 'P')
				ft_putimg(x, y, win, map[y][x]);
			x++;
		}
		y++;
	}
}
