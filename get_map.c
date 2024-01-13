/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:13:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/13 19:05:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <limits.h>

int	ft_countline_fd(int fd)
{
	size_t	line_count;
	ssize_t	rd;
	char	*buf;
	size_t	i;

	i = 0;
	line_count = 0;
	buf = ft_calloc(1, 1);
	// buf = 0;
	while (i < ULONG_MAX)
	{
		rd = read(fd, buf, 1);
		if (rd == -1 || rd == 0)
			break ;
		else if (buf[0] == '\n')
			line_count++;
		i++;
	}
	return (line_count);
}

char	**ft_read_map(char	*file_name)
{
	char	**map_read;
	int		fd;
	int		line_count;
	size_t	i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	line_count = ft_countline_fd(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	map_read = ft_calloc(sizeof(char *), line_count);
	while (i < ULONG_MAX)
	{
		map_read[i] = get_next_line(fd);
		if (map_read[i] == NULL)
			break ;
		i++;
	}
	map_read[i] = NULL;
	close(fd);
	return (map_read);
}
