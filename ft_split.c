/* ************************************************************************** */
/*                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/15 00:01:37 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	qty;

	i = 0;
	qty = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] == c)
			i++;
		if (s[i] - 1)
			qty++;
	}
	return (qty);
}

int	malloc_word(char **newstr, int word_count, int split)
{
	newstr[word_count] = (char *)malloc(sizeof(char) * (split + 1));
	if (!newstr[word_count])
	{
		while (word_count-- >= 0)
			free(newstr[word_count]);
		return (1);
	}
	return (0);
}

char	**split_words(char **newstr, char const *s, char c, int word_count)
{
	int	j;
	int	split;

	while (*s)
	{
		split = 1;
		j = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			split++;
		}
		if (split != 1)
		{
			if (malloc_word(newstr, word_count, split))
				return (NULL);
			while (--split > 0)
				newstr[word_count][j++] = *(s - split);
			newstr[word_count][j] = '\0';
			word_count++;
		}
	}
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char	**newstr;
	int		qty;
	int		word_count;

	word_count = 0;
	qty = 0;
	if (s == NULL)
		return (NULL);
	if (c != '\0')
		qty = count_words(s, c);
	if (!qty)
		qty = 1;
	newstr = (char **)malloc(sizeof(char *) * qty + 1);
	if (!newstr)
		return (NULL);
	if (c != '\0')
		newstr = split_words(newstr, s, c, word_count);
	if (newstr == NULL)
		return (NULL);
	newstr[qty] = NULL;
	return (newstr);
}
