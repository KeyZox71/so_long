/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/19 14:43:12 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "so_long.h"

void	ft_putplayer(t_window *win)
{
	ft_putimg(win->p_coords->x, win->p_coords->y, win, P_PNG);
}

void	ft_putimg(size_t x, size_t y, t_window *win, char *file_path)
{
	int		img_x;
	int		img_y;
	size_t	img_xy;

	img_x = 0;
	img_y = 0;
	img_xy = x + (y * win->map_size->x);
	ft_printf("%d\n", img_xy);
	if (win->img[img_xy])
		mlx_destroy_image(win->mlx, win->img[img_xy]);
	ft_putstr_fd(file_path, 1);
	ft_putchar_fd('\n', 1);
	win->img[img_xy] = mlx_png_file_to_image(win->mlx, file_path, &img_x, &img_y);
	mlx_put_image_to_window(win->mlx, win->win, win->img[img_xy], x * img_x, y * img_y);
}

void	ft_printmap(char **map, t_window *win)
{
	size_t	x;
	size_t	y;

	y = 0;
	win->c_count = 0;
	while (map[y] != NULL && y < ULONG_MAX)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				ft_putimg(x, y, win, W_PNG);
			else if (map[y][x] == '0')
				ft_putimg(x, y, win, G_PNG);
			else if (map[y][x] == 'C')
			{
				ft_putimg(x, y, win, C_PNG);
				win->c_count++;
			}
			else if (map[y][x] == 'E')
			{
				win->e_coords->x = x;
				win->e_coords->y = y;
				ft_putimg(x, y, win, E_PNG);
			}
			else if (map[y][x] == 'P')
			{
				win->p_coords->y = y;
				win->p_coords->x = x;
				ft_putimg(x, y, win, P_PNG);
			}

			x++;
		}
		y++;
	}
}
