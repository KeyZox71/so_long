/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:38:00 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/28 18:12:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freeimg(t_window *win)
{
	mlx_destroy_image(win->mlx, win->img->ground);
	mlx_destroy_image(win->mlx, win->img->collectible);
	mlx_destroy_image(win->mlx, win->img->exit);
	mlx_destroy_image(win->mlx, win->img->player);
	mlx_destroy_image(win->mlx, win->img->wall);
	free (win->img);
}

size_t	ft_mapsize(char	**map)
{
	size_t	i;

	i = 0;
	while (*map && i < SIZE_MAX)
	{
		map++;
		i++;
	}
	return (i);
}

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
	mlx_loop_end(win->mlx);
	mlx_destroy_display(win->mlx);
	ft_freemap(win->map);
	free(win->p_coords);
	free(win->e_coords);
	free(win);
	exit (EXIT_SUCCESS);
}
