/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:45:18 by adjoly            #+#    #+#             */
/*   Updated: 2023/11/09 14:31:55 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len_s;
	char	*result;

	len_s = ft_strlen(s);
	result = ft_memchr(s, c, len_s);
	if (c == 0)
		return ((char *)s + len_s);
	return (result);
}
