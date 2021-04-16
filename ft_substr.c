/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/14 21:02:36 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*store_substr(char *substr, char const *s,
	unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	size_t	s_len;

	i = 0;
	s_len = 0;
	substr = NULL;
	if (s == NULL)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	if (len <= 0 || start >= s_len || (start + len) > s_len || s == 0)
	{
		substr = (char *)malloc(sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	return (store_substr(substr, s, start, len));
}
