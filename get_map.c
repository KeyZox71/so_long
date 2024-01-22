/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:13:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/19 17:14:11 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_countline_fd(char	*file_name)
{
	size_t	line_count;
	ssize_t	rd;
	char	*buf;
	size_t	i;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		return (0);
	i = 0;
	line_count = 0;
	buf = ft_calloc(1, 1);
	while (i < ULONG_MAX)
	{
		rd = read(fd, buf, 1);
		if (rd == -1 || rd == 0)
			break ;
		else if (buf[0] == '\n')
			line_count++;
		i++;
	}
	close(fd);
	free(buf);
	return (line_count);
}

char	**ft_read_map(char	*file_name)
{
	char	**map_read;
	int		fd;
	size_t	i;
	size_t	ln_count;

	i = 0;
	ln_count = ft_countline_fd(file_name);
	if (ln_count == 0)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	map_read = ft_calloc(sizeof(char *), ln_count);
	if (!map_read)
	{
		close (fd);
		return (NULL);
	}
	while (i < ULONG_MAX)
	{
		map_read[i] = get_next_line(fd);
		if (map_read[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (map_read);
}
