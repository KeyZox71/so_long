/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:18:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/08 13:09:20 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "so_long.h"

int	key_close(int key, void *param)
{
	if (key == 41)
		mlx_loop_end(param);
	return (0);
}

int	win_close(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}

int	win_update(void *param)
{
	t_window	*win;

	win = (t_window *)param;
	mlx_pixel_put(win->mlx, win->win, 100, 100, 0xFFFFFF);
	mlx_clear_window(win->mlx, win->win);
	return (0);
}

int	main(int ac, char **av)
{
	t_window	*win;

	(void) ac;
	(void) av;
	win = ft_calloc(sizeof(t_window), 1);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1600, 900, "so_fluffy");

	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, key_close, win->mlx);
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, win_close, win->mlx);
	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, ft_move_character, win->mlx);
	mlx_loop_hook(win->mlx, win_update, win);
	mlx_loop(win->mlx);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win);
	return (0);
}
