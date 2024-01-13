/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:18:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/13 19:01:34 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	ft_freemap(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	win_close(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}

void	ft_exit(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	ft_freemap(win->map);
	free(win->p_coords);
	free(win->e_coords);
	free(win);
}

int	main(int ac, char **av)
{
	t_window	*win;
	char		**map;

	(void) ac;
	(void) av;
	map = ft_read_map(av[1]);
	win = malloc(sizeof(map) + sizeof(t_window));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1600, 900, "so_fluffy");
	win->map = map;
	win->mov_count = 0;
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, win_close, win->mlx);
	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, ft_key_event, win);
	// mlx_loop_hook(win->mlx, win_update, win);
	ft_printmap(win->map, win);
	mlx_loop(win->mlx);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	ft_freemap(win->map);
	free(win->p_coords);
	free(win->e_coords);
	free(win);
	return (0);
}
