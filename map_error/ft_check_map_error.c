/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:17:52 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 16:10:46 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	ft_checkcol(char **map, char c, unsigned short col)
{
	unsigned short	i;

	i = 0;
	while (map[i] && i < USHRT_MAX)
	{
		if (map[i][col] != c)
			return (1);
		i++;
	}
	return (0);
}

char	ft_is_rectangular(char **map)
{
	size_t	len_map;

	len_map = ft_strlen(*map);
	while (*map)
	{
		if (ft_strlen(*map) != len_map)
			return (1);
		map++;
	}
	return (0);
}

char	ft_valid_char(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_check_charset(map[y][x], "01CEP") == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	ft_checkline(char *map_line, char c)
{
	unsigned short	i;

	i = 0;
	while (*map_line && i < USHRT_MAX)
	{
		if (*map_line != c)
			return (1);
		map_line++;
		i++;
	}
	return (0);
}

void	ft_check_map_error(char	**map)
{
	t_coords	*p_coords;

	p_coords = malloc(sizeof(t_coords));
	if (!p_coords)
		ft_send_error("Memory allocation failed\n", map);
	if (ft_is_empty(map) == 1)
	{
		free(p_coords);
		ft_send_error("Map is empty", map);
	}
	if (ft_valid_char(map) == 1)
	{
		free(p_coords);
		ft_send_error("Invalid character in map\n", map);
	}
	if (ft_is_rectangular(map) == 1)
	{
		free(p_coords);
		ft_send_error("Map is not rectengular\n", map);
	}
	ft_check_map_content(map, p_coords);
	ft_check_map_state(map, p_coords);
	free(p_coords);
}
