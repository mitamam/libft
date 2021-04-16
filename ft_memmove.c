/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/13 16:45:46 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	move_to_dst(unsigned char *c_dst, unsigned char *c_src, size_t len)
{
	unsigned char	tmp;

	if (c_dst < c_src)
	{
		while (len-- > 0)
		{
			tmp = *c_src++;
			*c_dst++ = tmp;
		}
	}
	else
	{
		while (len-- > 0)
		{
			tmp = *(c_src + len);
			*(c_dst + len) = tmp;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (dst || src)
		move_to_dst(c_dst, c_src, len);
	return (dst);
}
