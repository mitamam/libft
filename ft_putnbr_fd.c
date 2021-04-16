/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasuda <mmasuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 22:30:20 by mmasuda           #+#    #+#             */
/*   Updated: 2021/04/15 17:23:17 by mmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	calc_putnbr_fd(long num, int digit, int minus, int fd)
{
	int		i;
	char	s[256];

	i = 0;
	if (minus)
		digit++;
	if (minus)
	{
		s[i] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		s[digit - i - 1] = num % 10 + '0';
		num /= 10;
		i++;
	}
	s[digit] = '\0';
	write(fd, s, sizeof(char) * digit);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	int		digit;
	int		minus;

	num = n;
	digit = 0;
	minus = 0;
	if (num == 0)
		write(fd, "0", sizeof(char));
	if (num < 0)
	{
		num *= -1;
		minus = 1;
	}
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	num = n;
	calc_putnbr_fd(num, digit, minus, fd);
}
