/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/13 20:59:20 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strjoin_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*link_str(char	*newstr, char const *s1, char const *s2)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < strjoin_strlen(s1) && s1[i] != '\0')
	{
		newstr[c] = s1[i];
		i++;
		c++;
	}
	i = 0;
	while (i < strjoin_strlen(s2) && s2[i] != '\0')
	{
		newstr[c] = s2[i];
		i++;
		c++;
	}
	newstr[c] = '\0';
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL && s2 == NULL)
		return ("\0");
	s1_len = strjoin_strlen(s1);
	s2_len = strjoin_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!newstr)
		return (NULL);
	return (link_str(newstr, s1, s2));
}
