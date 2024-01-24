/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:17:52 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/24 12:35:46 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "so_long.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

char	ft_check_charset(char c, char *charset)
{
	unsigned short	i;

	i = 0;
	while (charset[i] && i < USHRT_MAX)
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

char	ft_check_file(char	*file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
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

char	ft_check_element(char **map, t_coords *p_coords)
{
	size_t	y;
	size_t	x;
	size_t	p_count;
	size_t	e_count;
	size_t	c_count;

	y = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				p_count++;
				p_coords->x = x;
				p_coords->y = y;
			}
			else if (map[y][x] == 'E')
				e_count++;
			else if (map[y][x] == 'C')
				c_count++;
			x++;
		}
		y++;
	}
	if (p_count != 1)
		return (1);
	else if (e_count != 1)
		return (2);
	else if (c_count < 1)
		return (3);
	return (0);
}

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

char	ft_is_empty(char **map)
{
	if (map[0][0] == '\0')
		return (1);
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

char	ft_valid_file_ext(char *file_name)
{
	unsigned short	file_len;

	file_len = ft_strlen(file_name) - 1;
	if (file_len <= 3)
		return (1);
	else if (file_name[file_len] == 'r' && file_name[file_len - 1] == 'e' \
		&& file_name[file_len - 2] == 'b' && file_name[file_len - 3] == '.')
		return (0);
	return (1);
}

void	ft_send_error(char *msg, char **map)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	if (map)
		ft_freemap(map);
	exit(EXIT_SUCCESS);
}

void	ft_check_map_error(char	**map)
{
	char		check_result;
	t_coords	*p_coords;

	p_coords = malloc(sizeof(t_coords));
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
	check_result = ft_check_element(map, p_coords);
	if (check_result == 1)
	{
		free(p_coords);
		ft_send_error("Invalid number of player\n", map);
	}
	if (check_result == 2)
	{
		free(p_coords);
		ft_send_error("Invalid number of exit\n", map);
	}
	if (check_result == 3)
	{
		free(p_coords);
		ft_send_error("Invalid number of collectible\n", map);
	}
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
	free(p_coords);
}
