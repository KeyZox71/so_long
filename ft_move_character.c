/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:13:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/07 22:37:53 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(void *param)
{
	
}

int	ft_move_down(void *param)
{
	
}

int	ft_move_left(void *param)
{
	
}

int	ft_move_right(void *param)
{

}

int	ft_move_character(int key, void *param)
{
	if (key == 26)
		ft_move_up(param);
	else if (key == 22)
		ft_move_down(param);
	else if (key == 4)
		ft_move_right(param);
	else if (key == 7)
		ft_move_left(param);
	ft_putnbr_fd(key, 1);
	return (0);
}
