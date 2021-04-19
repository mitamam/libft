/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/19 11:36:27 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	re_lstclear(t_list *lst, void(*del)(void *))
{
	if (!lst->next)
	{
		ft_lstdelone(lst, del);
		return ;
	}
	ft_lstdelone(lst, del);
	return (re_lstclear(lst->next, del));
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst && !del)
		return ;
	if (*lst)
		re_lstclear(*lst, del);
	*lst = NULL;
}
