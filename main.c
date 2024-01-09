/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:18:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/09 16:06:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "libft/libft.h"
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

/*int	win_update(void *param)
{
	t_window	*win;
	int			y;
	int			x;

	win = (t_window *)param;
	return (0);
}*/

int	main(int ac, char **av)
{
	t_window	*win;

	(void) ac;
	(void) av;
	win = ft_calloc(sizeof(t_window), 1);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1600, 900, "so_fluffy");
	char **map = ft_read_map(av[1]);

	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, key_close, win->mlx);
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, win_close, win->mlx);
	// mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, ft_move_character, win->mlx);
	// mlx_loop_hook(win->mlx, win_update, win);
	ft_printmap(map, win);
	mlx_loop(win->mlx);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win);
	return (0);
}
