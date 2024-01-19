/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:18:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/19 14:44:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MacroLibX/includes/mlx.h"
#include "printf/ft_printf.h"
#include "so_long.h"

void	ft_freeimg(t_window	*win)
{
	while (*win->img)
	{
		mlx_destroy_image(win, *win->img);
		win->img++;
	}
	free(win->img);
	return ;
}

size_t	ft_sizemap(char	**map)
{
	size_t	i;

	i = 0;
	while (*map)
	{
		map++;
		i++;
	}
	return (i);
}

void	ft_freemap(char	**map)
{
	while (*map)
	{
		free(*map);
		map++;
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
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	ft_freemap(win->map);
	ft_freeimg(win);
	free(win->p_coords);
	free(win->e_coords);
	free(win);
	exit (0);
}

int	main(int ac, char **av)
{
	t_window	*win;
	char		**map;
	void		**img;
	t_coords	*map_size;

	(void) ac;
	(void) av;
	map = NULL;
	if (ft_valid_file_ext(av[1]) == 1)
		ft_send_error("Invalid map file extension (not .ber)\n", map);
	map = ft_read_map(av[1]);
	if (!map)
		return (0);
	ft_check_map_error(map);
	map_size = malloc(sizeof(t_coords));
	if (!map_size)
	{
		ft_freemap(map);
		return (0);
	}
	map_size->x = ft_strlen(map[0]);
	map_size->y = ft_sizemap(map);
	ft_printf("x: %d\n", map_size->x);
	ft_printf("y: %d\n", map_size->y);
	img = malloc((map_size->x * map_size->y) * sizeof(void *));
	if (!img)
	{
		free(map_size);
		ft_freemap(map);
		return (0);
	}
	win = malloc(sizeof(map) + sizeof(t_window) + sizeof(img));
	win->img = img;
	if (!win)
	{
		ft_freemap(map);
		return (0);
	}
	win->mlx = mlx_init();
	if (!win->mlx)
	{
		// free map img win;
		return (0);
	}
	win->win = mlx_new_window(win->mlx, 1600, 900, "so_fluffy");
	if (!win->win)
	{
		// free map img win ; destroy mlx
		return (0);
	}
	win->map = map;
	win->map_size = map_size;
	win->p_coords = malloc(sizeof(t_coords));
	win->e_coords = malloc(sizeof(t_coords));
	win->mov_count = 0;
	mlx_on_event(win->mlx, win->win, MLX_WINDOW_EVENT, win_close, win->mlx);
	mlx_on_event(win->mlx, win->win, MLX_KEYDOWN, ft_key_event, win);
	ft_printmap(win->map, win);
	mlx_loop(win->mlx);
	ft_exit(win);
	return (0);
}
