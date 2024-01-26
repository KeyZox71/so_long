/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:13:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 16:10:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_printmov(t_window *win)
{
	win->mov_count++;
	ft_printf("Mouvement : %d\n", win->mov_count);
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
	return (0);
}
