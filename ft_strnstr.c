/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/15 15:24:22 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(haystack || needle))
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len)
	{
		j = 0;
		while (j < ft_strlen(needle) && j < ft_strlen(haystack)
			&& (i + j) < len)
		{
			if (haystack[i + j] < needle[j] || haystack[i + j] > needle[j])
				break ;
			else
				j++;
		}
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i += j + 1;
	}
	return (NULL);
}
