/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:13:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/13 17:13:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "libft/libft.h"
#include "so_long.h"

void	ft_move_up(t_window *win)
{
	if (win->map[win->p_coords->y - 1][win->p_coords->x] != '1')
	{
	ft_putimg(win->p_coords->x, win->p_coords->y - 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->y = win->p_coords->y - 1;
		ft_putstr_fd("UP", 1);
	}
}

void	ft_move_down(t_window *win)
{
	if (win->map[win->p_coords->y + 1][win->p_coords->x] != '1')
	{
		ft_putimg(win->p_coords->x, win->p_coords->y + 1, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->y = win->p_coords->y + 1;
		ft_putstr_fd("UP", 1);
	}
}

void	ft_move_left(t_window *win)
{
	if (win->map[win->p_coords->y][win->p_coords->x - 1] != '1')
	{
		ft_putimg(win->p_coords->x - 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->x = win->p_coords->x - 1;
		ft_putstr_fd("UP", 1);
	}
}

void	ft_move_right(t_window *win)
{
	if (win->map[win->p_coords->y][win->p_coords->x + 1] != '1')
	{
		ft_putimg(win->p_coords->x + 1, win->p_coords->y, win, P_PNG);
		ft_putimg(win->p_coords->x, win->p_coords->y, win, G_PNG);
		win->p_coords->x = win->p_coords->x + 1;
		ft_putstr_fd("UP", 1);
	}
	(void)win;
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
	return (0);
}
