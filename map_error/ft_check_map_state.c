/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:36:23 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 16:10:55 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_flood(int x, int y, char	**map)
{
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		ft_flood(x - 1, y, map);
		ft_flood(x + 1, y, map);
		ft_flood(x, y - 1, map);
		ft_flood(x, y + 1, map);
	}
}

char	ft_floodfill(char **map, t_coords *p_coords)
{
	size_t	x;
	size_t	y;

	ft_flood(p_coords->x, p_coords->y, map);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	ft_is_closed(char **map)
{
	unsigned short	size_map;
	unsigned short	size_line;
	unsigned short	i;
	unsigned short	res;

	i = 0;
	size_map = ft_mapsize(map);
	size_line = ft_strlen(map[0]);
	res = ft_checkcol(map, '1', 0);
	res += ft_checkcol(map, '1', size_line - 1);
	res += ft_checkline(map[0], '1');
	res += ft_checkline(map[size_map - 1], '1');
	if (res > 0)
		return (1);
	return (0);
}

void	ft_check_map_state(char **map, t_coords *p_coords)
{
	if (ft_is_closed(map) == 1)
	{
		free(p_coords);
		ft_send_error("Map is not closed\n", map);
	}
	if (ft_floodfill(map, p_coords) == 1)
	{
		free(p_coords);
		ft_send_error("Map is cannot be finished\n", map);
	}
}
