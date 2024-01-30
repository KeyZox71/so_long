/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:27 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/30 08:26:30 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_down2(t_window *win, char c, char nxt)
{
	ft_putimg(win->p_coords->x, win->p_coords->y, win, c);
	ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, nxt);
	ft_printmov(win);
}

void	ft_move_down(t_window *win)
{
	if (win->map[win->p_coords->y + 1][win->p_coords->x] == 'C')
	{
		if (win->p_coords->y == win->e_coords->y
			&& win->p_coords->x == win->e_coords->x)
			ft_putimg(win->p_coords->x, win->p_coords->y, win, 'E');
		else
			ft_putimg(win->p_coords->x, win->p_coords->y, win, '0');
		win->map[win->p_coords->y + 1][win->p_coords->x] = '0';
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, 'P');
		win->c_count--;
		ft_printmov(win);
	}
	else if (win->p_coords->y == win->e_coords->y
		&& win->e_coords->x == win->p_coords->x
		&& win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
		ft_move_down2(win, 'E', 'P');
	else if (win->map[win->p_coords->y + 1][win->p_coords->x] == 'E'
		&& win->c_count == 0)
	{
		ft_printmov(win);
		ft_exit(win);
	}
	else if (win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
		ft_move_down2(win, '0', 'P');
}
