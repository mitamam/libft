/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/13 21:00:02 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] != '\0')
		d_len++;
	if (dstsize < d_len)
	{
		while (src[s_len] != '\0')
			s_len++;
		return (dstsize + s_len);
	}
	while (d_len < dstsize - 1 && dstsize > 0 && src[s_len])
		dst[d_len++] = src[s_len++];
	dst[d_len] = '\0';
	while (src[s_len++] != '\0')
		d_len++;
	return (d_len);
}
