/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:18:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/28 18:28:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*ft_init_window(char **map)
{
	t_window	*win;

	win = malloc(sizeof(map) + sizeof(t_window));
	if (!win)
		ft_clear_alloc(win, map);
	win->p_coords = malloc(sizeof(t_coords));
	if (!win->p_coords)
		ft_clear_alloc(win, map);
	win->e_coords = malloc(sizeof(t_coords));
	if (!win->e_coords)
		ft_clear_alloc(win, map);
	win->img = malloc(sizeof(t_img));
	if (!win->img)
		ft_clear_alloc(win, map);
	win->mlx = mlx_init();
	if (!win->mlx)
		ft_clear_alloc(win, map);
	return (win);
}

char	**ft_map_setup(char **map, char **av)
{
	map = ft_read_map(av[1], map);
	if (!map)
		exit(EXIT_SUCCESS);
	if (!map[0])
		ft_send_error("Map is empty\n", map);
	ft_check_map_error(map);
	ft_freemap(map);
	map = ft_read_map(av[1], map);
	if (!map)
		ft_send_error("Memory allocation failed\n", map);
	return (map);
}

void	ft_play(t_window *win)
{
	win->mov_count = 0;
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, win_close, win);
	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, ft_key_event, win);
	ft_alloc_img(win);
	ft_printmap(win->map, win);
	mlx_loop(win->mlx);
	ft_exit(win);
}

int	main(int ac, char **av)
{
	t_window	*win;
	char		**map;
	t_coords	map_size;

	(void) ac;
	map = NULL;
	if (ac != 2)
		ft_send_error("Invalid number of argument\n", map);
	if (ft_valid_file_ext(av[1]) == 1)
		ft_send_error("Invalid map file extension (not .ber)\n", map);
	if (ft_check_file(av[1]) == 1)
		ft_send_error("File cannot be opened or doesn't exist\n", map);
	if (ft_checknl(av[1]) == 1)
		ft_send_error("File containt empty line\n", map);
	map = ft_map_setup(map, av);
	map_size.x = ft_strlen(map[0]);
	map_size.y = ft_mapsize(map);
	win = ft_init_window(map);
	win->win = mlx_new_window(win->mlx,
			map_size.x * T_SIZE, map_size.y * T_SIZE, "so_fluffy");
	if (!win->win)
		ft_destroy_display(win, map);
	win->map = map;
	ft_play(win);
}
