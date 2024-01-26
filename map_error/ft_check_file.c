/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:29:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 16:10:23 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	ft_is_empty(char **map)
{
	if (map[0][0] == '\0')
		return (1);
	return (0);
}
