/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:18:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/22 13:46:27 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeimg(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img->collectible);
	mlx_destroy_image(win->mlx, win->img->exit);
	mlx_destroy_image(win->mlx, win->img->ground);
	mlx_destroy_image(win->mlx, win->img->player);
	mlx_destroy_image(win->mlx, win->img->wall);
	free (win->img);
}


void	ft_freemap(char	**map)
{
	size_t	i;

	i = 0;
	while (map[i] && i < ULONG_MAX)
	{
		// ft_printf("freed : %s\n", map[i]);
		free(map[i]);
		i++;
	}
	// free(map);
}

int	win_close(int event, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (event == 0)
		ft_exit(win);
	return (0);
}

void	ft_exit(t_window *win)
{
	ft_freeimg(win);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	ft_freemap(win->map);
	// free(win->p_coords);
	// free(win->e_coords);
	// free(win);
	exit (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_window	*win;
	char		**map;

	(void) ac;
	map = NULL;
	if (ac != 2)
		ft_send_error("Invalid number of argument\n", map);
	if (ft_valid_file_ext(av[1]) == 1)
		ft_send_error("Invalid map file extension (not .ber)\n", map);
	if (ft_check_file(av[1]) == 1)
		ft_send_error("File cannot be opened or doesn't exist\n", map);
	map = ft_read_map(av[1]);
	if (!map)
		exit(EXIT_SUCCESS);
	if (!map[0])
		ft_send_error("Map is empty", map);
	ft_check_map_error(map);
	win = malloc(sizeof(map) + sizeof(t_window));
	if (!win)
	{
		ft_freemap(map);
		return (0);
	}
	// protect all three
	win->p_coords = malloc(sizeof(t_coords));
	win->e_coords = malloc(sizeof(t_coords));
	win->img = malloc(sizeof(t_img));
	win->mlx = mlx_init();
	if (!win->mlx)
		// free map img win;
		return (0);
	win->win = mlx_new_window(win->mlx, 1600, 900, "so_fluffy");
	if (!win->win)
		// free map img win ; destroy mlx
		return (0);
	win->map = map;
	win->mov_count = 0;
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, win_close, win->mlx);
	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, ft_key_event, win);
	ft_alloc_img(win);
	ft_printmap(win->map, win);
	mlx_loop(win->mlx);
	ft_exit(win);
	return (0);
}
