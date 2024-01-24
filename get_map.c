/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:13:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/23 11:45:20 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "so_long.h"
#include <stddef.h>

size_t	ft_filesize(char *file_name)
{
	size_t	i;
	int		fd;
	ssize_t	rd;
	char	*buf;

	fd = open(file_name, O_RDONLY);
	buf = ft_calloc(1, 1);
	if (!buf)
		return (0);
	i = 0;
	while (buf && i < SIZE_MAX)
	{
		rd = read(fd, buf, 1);
		if (rd <= 0)
			break ;
		i++;
	}
	free(buf);
	close(fd);
	return (i);
}

char	**ft_getmap(int fd, char **map_read, char *buf, char *tmp)
{
	ssize_t	rd;
	size_t	i;

	i = 0;
	while (buf && i < SIZE_MAX)
	{
		rd = read(fd, buf, 1);
		if (rd <= 0)
			break ;
		tmp[i] = buf[0];
		i++;
	}
	close(fd);
	tmp[i] = '\0';
	map_read = ft_split(tmp, '\n');
	return (map_read);
}

char	**ft_read_map(char	*file_name, char	**map_read)
{
	int		fd;
	char	*tmp;
	char	*buf;
	size_t	filesize;

	filesize = ft_filesize(file_name);
	if (filesize == 0)
		return (NULL);
	tmp = ft_calloc(filesize + 1, 1);
	if (!tmp)
		return (NULL);
	buf = ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	map_read = ft_getmap(fd, map_read, buf, tmp);
	free(buf);
	free(tmp);
	return (map_read);
}
