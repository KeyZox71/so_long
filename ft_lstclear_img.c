/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:05:14 by adjoly            #+#    #+#             */
/*   Updated: 2024/01/14 15:18:13 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstdelone_img(t_list *lst, void *param, void (*del)(void *, void *))
{

	if (lst == NULL || del == NULL)
		return ;
	del(lst->content, param);
	free(lst);
}

void	ft_lstclear_img(t_list **lst, void *param, void (*del)(void *, void *))
{
	t_list	*tmp;

	tmp = NULL;
	while (lst && *lst && del)
	{
		tmp = (*lst)->next;
		ft_lstdelone_img((*lst), param, del);
		*lst = tmp;
	}
}
