/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/13 16:38:51 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*char_s;
	unsigned char		char_c;
	size_t				i;

	char_s = (unsigned char *)s;
	char_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == char_c)
			return (&char_s[i]);
		i++;
	}
	return (NULL);
}
