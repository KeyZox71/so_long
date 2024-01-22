/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:17:52 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/22 13:24:41 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "so_long.h"
#include <limits.h>

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
		return (1);
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
			if (ft_check_charset(map[y][x], "01CEP\n") == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	ft_check_player(char **map)
{
	size_t	y;
	size_t	x;
	size_t	p_count;

	y = 0;
	p_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				p_count++;
			x++;
		}
		y++;
	}
	if (p_count == 1)
		return (0);
	return (1);
}

char	ft_check_exit(char **map)
{
	size_t	y;
	size_t	x;
	size_t	p_count;

	y = 0;
	p_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				p_count++;
			x++;
		}
		y++;
	}
	if (p_count == 1)
		return (0);
	return (1);
}

char	ft_check_collectible(char **map)
{
	size_t	y;
	size_t	x;
	size_t	c_count;

	y = 0;
	c_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				c_count++;
			x++;
		}
		y++;
	}
	if (c_count >= 1)
		return (0);
	return (1);
}

/*char	ft_floodfill(char **map)
{
	while (expression)
	{
		
	}
	// partir dans toutes les direction a partir du P et sur tout les point suivant
}*/

char	ft_valid_file_ext(char *file_name)
{
	unsigned short	file_len;

	file_len = ft_strlen(file_name) - 1;
	if (file_len < 3)
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
	if (ft_valid_char(map) == 1)
		ft_send_error("Invalid character in map\n", map);
	else if (ft_check_player(map) == 1)
		ft_send_error("Invalid number of player\n", map);
	else if (ft_check_collectible(map) == 1)
		ft_send_error("Invalid number of collectible\n", map);
	else if (ft_check_exit(map) == 1)
		ft_send_error("Invalid number of exit\n", map);
	// else if ()
	// else if (ft_floodfill(map) == 1)
		// ft_send_error("Map is cannot be finished\n", map);
}
