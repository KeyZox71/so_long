/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:21:23 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/28 18:24:09 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_alloc(t_window *win, char **map)
{
	if (win->p_coords)
		free(win->p_coords);
	if (win->e_coords)
		free(win->e_coords);
	if (win->img)
		free(win->img);
	if (win)
		free(win);
	ft_freemap(map);
	ft_putstr_fd("Memory allocation failed\n", STDOUT_FILENO);
	exit (EXIT_SUCCESS);
}

void	ft_destroy_display(t_window *win, char **map)
{
	mlx_destroy_display(win->mlx);
	ft_clear_alloc(win, map);
}
