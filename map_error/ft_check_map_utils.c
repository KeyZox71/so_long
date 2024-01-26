/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:28:38 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/26 16:12:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_send_error(char *msg, char **map)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	if (map)
		ft_freemap(map);
	exit(EXIT_SUCCESS);
}

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
