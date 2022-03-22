/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:00:31 by jabae             #+#    #+#             */
/*   Updated: 2022/03/22 01:31:34 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	strnum;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	strnum = n % 10 + 48;
	write(fd, &strnum, 1);
}

size_t ft_putstr_count(char *str)
{
	size_t	str_len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = ft_strlen(str);
	write(1, str, str_len);
	return (str_len);
}

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_count_digit(int num)
{
	int count;

	count = 1;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num / 10 > 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}
