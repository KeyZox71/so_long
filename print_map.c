/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:30:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/13 17:56:32 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "so_long.h"
#include <stdio.h>
#include <stddef.h>

void	ft_putimg(size_t x, size_t y, t_window *win, char *file_path)
{
	int	img_x;
	int	img_y;

	img_x = 0;
	img_y = 0;
	ft_putstr_fd(file_path, 1);
	ft_putchar_fd('\n', 1);
	win->img = mlx_png_file_to_image(win->mlx, file_path, &img_x, &img_y);
	mlx_put_image_to_window(win->mlx, win->win, win->img, x * img_x, y * img_y);
}

void	ft_printmap(char **map, t_window *win)
{
	int		x;
	int		y;

	y = 0;
	// win->c_count = malloc(1 * sizeof(size_t));
	win->c_count = 0;
	while (map[y])
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
				win->e_coords = malloc(sizeof(t_coords *));
				win->e_coords->x = x;
				win->e_coords->y = y;
				ft_putimg(x, y, win, E_PNG);
			}
			else if (map[y][x] == 'P')
			{
				win->p_coords = malloc(sizeof(t_coords *));
				win->p_coords->y = y;
				win->p_coords->x = x;
				ft_putimg(x, y, win, P_PNG);
			}
			x++;
		}
		y++;
	}
}
