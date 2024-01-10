/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:13:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/10 15:10:58 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	ft_putimg(*win->player_x, *win->player_y - 1, win, "assets/player.png");
}

void	ft_move_down(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	ft_putimg(*win->player_x, *win->player_y + 1, win, "assets/player.png");
}

void	ft_move_left(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	ft_putimg(*win->player_x - 1, *win->player_y, win, "assets/player.png");
}

void	ft_move_right(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	ft_putimg(*win->player_x + 1, *win->player_y, win, "assets/player.png");
}

int	ft_move_character(int key, void *param)
{
	if (key == 26)
		ft_move_up(param);
	else if (key == 22)
		ft_move_down(param);
	else if (key == 4)
		ft_move_right(param);
	else if (key == 7)
		ft_move_left(param);
	return (0);
}
