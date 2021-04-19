/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/19 09:59:27 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	re_count_elem(t_list *lst, int elem_qty)
{
	t_list	*node;

	node = lst;
	while (node->next != NULL)
	{
		elem_qty++;
		node = node->next;
	}
	return (elem_qty + 1);
}

int	ft_lstsize(t_list *lst)
{
	int	elem_qty;

	elem_qty = 0;
	if (lst)
		return (re_count_elem(lst, elem_qty));
	return (elem_qty);
}
