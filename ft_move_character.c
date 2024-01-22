/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:13:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/21 15:29:10 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_window *win)
{
	if (win->map[win->p_coords->y - 1][win->p_coords->x] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y - 1][win->p_coords->x] = '0';
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, 'P');
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, 'E');
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, 'P');
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] == 'E'
		&& win->c_count == 0)
	{
		ft_printf("Mouvement : %d\n", win->mov_count + 1);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, 'P');
		win->mov_count++;
	}
}

void	ft_move_down(t_window *win)
{
	if (win->map[win->p_coords->y + 1][win->p_coords->x] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y + 1][win->p_coords->x] = '0';
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, 'P');
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, 'E');
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, 'P');
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y + 1][win->p_coords->x] == 'E'
		&& win->c_count == 0)
	{
		ft_printf("Mouvement : %d\n", win->mov_count + 1);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, 'P');
		win->mov_count++;
	}
}

void	ft_move_left(t_window *win)
{
	if (win->map[win->p_coords->y][win->p_coords->x - 1] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y][win->p_coords->x - 1] = '0';
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, 'P');
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y][win->p_coords->x - 1] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, 'E');
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, 'P');
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y][win->p_coords->x - 1] == 'E'
		&& win->c_count == 0)
	{
		ft_printf("Mouvement : %d\n", win->mov_count + 1);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x - 1] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, 'P');
		win->mov_count++;
	}
}

void	ft_move_right(t_window *win)
{
	if (win->map[win->p_coords->y][win->p_coords->x + 1] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y][win->p_coords->x + 1] = '0';
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, 'P');
		win->c_count--;
		win->mov_count++;
	}
	else if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, 'E');
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, 'P');
		win->mov_count++;
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] == 'E'
		&& win->c_count == 0)
	{
		ft_printf("Mouvement : %d\n", win->mov_count + 1);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, 'P');
		win->mov_count++;
	}
}

int	ft_key_event(int key, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (key == 41)
		ft_exit(win);
	if (key == 26 || key == 82)
		ft_move_up(win);
	else if (key == 22 || key == 81)
		ft_move_down(win);
	else if (key == 4 || key == 80)
		ft_move_left(win);
	else if (key == 7 || key == 79)
		ft_move_right(win);
	ft_printf("Mouvement : %d\n", win->mov_count);
	return (0);
}
