/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:31:27 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 16:10:32 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	ft_check_reselement(t_elemcount *count)
{
	if (count->p_count != 1)
		return (1);
	else if (count->e_count != 1)
		return (2);
	else if (count->c_count < 1)
		return (3);
	return (0);
}

char	ft_check_element(char **map, t_coords *p_coords, t_elemcount *count)
{
	int			y;
	int			x;

	y = -1;
	count->c_count = 0;
	count->e_count = 0;
	count->p_count = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				count->p_count++;
				p_coords->x = x;
				p_coords->y = y;
			}
			else if (map[y][x] == 'E')
				count->e_count++;
			else if (map[y][x] == 'C')
				count->c_count++;
		}
	}
	return (ft_check_reselement(count));
}

void	ft_check_map_content(char **map, t_coords *p_coords)
{
	char		check_result;
	t_elemcount	*count;

	count = malloc(sizeof(t_elemcount *));
	check_result = ft_check_element(map, p_coords, count);
	if (check_result == 1)
	{
		free(count);
		free(p_coords);
		ft_send_error("Invalid number of player\n", map);
	}
	if (check_result == 2)
	{
		free(count);
		free(p_coords);
		ft_send_error("Invalid number of exit\n", map);
	}
	if (check_result == 3)
	{
		free(count);
		free(p_coords);
		ft_send_error("Invalid number of collectible\n", map);
	}
}
