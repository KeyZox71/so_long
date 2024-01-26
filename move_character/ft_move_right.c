/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:32 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 17:44:49 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_right(t_window *win)
{
	if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, 'E');
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, 'P');
		ft_printmov(win);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y][win->p_coords->x + 1] = '0';
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, 'P');
		win->c_count--;
		ft_printmov(win);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] == 'E'
		&& win->c_count == 0)
	{
		ft_printmov(win);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, 'P');
		ft_printmov(win);
	}
}
