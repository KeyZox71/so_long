/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/27 16:50:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_up2(t_window *win, char c, char nxt)
{
	ft_putimg(win->p_coords->x, win->p_coords->y, win, c);
	ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, nxt);
	ft_printmov(win);
}

void	ft_move_up(t_window *win)
{
	if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
		ft_move_up2(win, 'E', 'P');
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] == 'E'
		&& win->c_count == 0)
	{
		ft_printmov(win);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] == 'C')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y - 1][win->p_coords->x] = '0';
		ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, 'P');
		win->c_count--;
		ft_printmov(win);
	}
	else if (win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
		ft_move_up2(win, '0', 'P');
}
