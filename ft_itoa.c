/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/13 16:31:55 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_num(long num, int *minus)
{
	int	digit;

	digit = 0;
	if (num < 0)
	{
		num *= -1;
		*minus = 1;
	}
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

char	*calc_itoa(long num, int minus, int digit)
{
	int		i;
	char	*str;

	i = 0;
	if (minus)
		digit++;
	str = (char *)malloc((sizeof(char) * (digit + 1)));
	if (!str)
		return (NULL);
	if (minus)
	{
		str[i] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[digit - i - 1] = num % 10 + '0';
		num /= 10;
		i++;
	}
	str[digit] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	int		digit;
	int		minus;
	char	*str;

	num = (long)n;
	digit = 0;
	minus = 0;
	if (num == 0)
	{
		str = (char *)malloc((sizeof(char) * 2));
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	digit = check_num(num, &minus);
	return (calc_itoa(num, minus, digit));
}
