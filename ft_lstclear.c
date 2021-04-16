/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/13 16:34:30 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	re_lstclear(t_list *lst, void(*del)(void *))
{
	if (lst->next == NULL)
	{
		ft_lstdelone(lst, del);
		return ;
	}
	ft_lstdelone(lst, del);
	return (re_lstclear(lst->next, del));
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst[0] != (void *)0)
		re_lstclear(lst[0], del);
	*lst = NULL;
}
