/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:13:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/19 15:25:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "so_long.h"

void	ft_printmapchar(char **map)
{
	while (*map)
	{
		ft_printf("%s\n", *map);
		map++;
	}
	return ;
}

void	ft_move_up(t_window *win)
{
	if (win->map[win->p_coords->y - 1][win->p_coords->x] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->map[win->p_coords->y - 1][win->p_coords->x] = '0';
		win->p_coords->y = win->p_coords->y - 1;
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y && win->e_coords->x == win->p_coords->x && win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, E_PNG);
		win->p_coords->y = win->p_coords->y - 1;
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] == 'E' && win->c_count == 0)
	{
		win->mov_count++;
		ft_printf("%d\n", win->c_count);
		exit(0);
	}
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->y = win->p_coords->y - 1;
		win->mov_count++;
	}
}

void	ft_move_down(t_window *win)
{
	if (win->map[win->p_coords->y + 1][win->p_coords->x] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->map[win->p_coords->y + 1][win->p_coords->x] = '0';
		win->p_coords->y = win->p_coords->y + 1;
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y && win->e_coords->x == win->p_coords->x && win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, E_PNG);
		win->p_coords->y = win->p_coords->y + 1;
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y + 1][win->p_coords->x] == 'E' && win->c_count == 0)
	{
		win->mov_count++;
		ft_printf("%d\n", win->c_count);
		exit(0);
	}
	else if (win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->y = win->p_coords->y + 1;
		win->mov_count++;
	}
}

void	ft_move_left(t_window *win)
{
	if (win->map[win->p_coords->y][win->p_coords->x - 1] == 'C')
	{
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->map[win->p_coords->y][win->p_coords->x - 1] = '0';
		win->p_coords->x = win->p_coords->x - 1;
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y && win->e_coords->x == win->p_coords->x && win->map[win->p_coords->y][win->p_coords->x - 1] != '1')
	{
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, E_PNG);
		win->p_coords->x = win->p_coords->x - 1;
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y][win->p_coords->x - 1] == 'E' && win->c_count == 0)
	{
		win->mov_count++;
		ft_printf("%d\n", win->c_count);
		exit(0);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x - 1] != '1')
	{
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->x = win->p_coords->x - 1;
		win->mov_count++;
	}
}

void	ft_move_right(t_window *win)
{
	if (win->map[win->p_coords->y][win->p_coords->x + 1] == 'C')
	{
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->map[win->p_coords->y][win->p_coords->x + 1] = '0';
		win->p_coords->x = win->p_coords->x - 1;
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y && win->e_coords->x == win->p_coords->x && win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, E_PNG);
		win->p_coords->x = win->p_coords->x + 1;
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] == 'E' && win->c_count == 0)
	{
		win->mov_count++;
		ft_printf("%d\n", win->c_count);
		exit(0);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->x = win->p_coords->x + 1;
		win->mov_count++;
	}
}

int	ft_key_event(int key, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (key == 41)
		mlx_loop_end(win->mlx);
	// UP/W
	if (key == 26)
		ft_move_up(win);
	// DOWN/S
	else if (key == 22)
		ft_move_down(win);
	// LEFT/A
	else if (key == 4)
		ft_move_left(win);
	// RIGHT/D
	else if (key == 7)
		ft_move_right(win);
	ft_printf("Mouvement : %d\n", win->mov_count);
	// ft_printmap(win->map, win);
	// ft_printmapchar(win->map);
	// ft_printf("%d\n", win->e_coords->x);
	// ft_printf("%d\n", win->e_coords->y);
	// ft_printf("%d\n", win->p_coords->x);
	// ft_printf("%d\n", win->p_coords->y);
	return (0);
}
