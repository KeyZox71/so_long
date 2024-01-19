/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:17:52 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/18 13:51:13 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "so_long.h"
#include <stddef.h>
#include <stdlib.h>

char	ft_check_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c != *charset)
			return (1);
		charset++;
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
			if (ft_check_charset(map[y][x], "01CEP") == 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
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
	if (file_name[file_len] == 'r' && file_name[file_len - 1] == 'e' \
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
	// else if (ft_floodfill(map) == 1)
		// ft_send_error("Map is not finishable\n", map);
}
