/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:08:00 by jabae             #+#    #+#             */
/*   Updated: 2022/03/24 18:55:49 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *str)
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

int	ft_putint_count(long long num)
{
	int	count;

	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr_fd(num, 1);
	count = 1;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num / 10 > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_putunsignedint_count(unsigned int num)
{
	int	count;

	ft_putnbr_fd(num, 1);
	count = 1;
	while (num / 10 > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_puthex_count(unsigned int num, char *hexbase)
{
	char	result[16];
	int		idx;
	int		count;

	if (!hexbase)
		return (-1);
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	idx = 0;
	while (num && idx < 16)
	{
		result[idx] = hexbase[num % 16];
		num /= 16;
		idx++;
	}
	count = idx;
	while (--idx >= 0)
		write(1, &result[idx], 1);
	return (count);
}

int	ft_putpointer_count(unsigned long long num, char *hexbase)
{
	char	result[16];
	int		idx;
	int		count;

	if (!hexbase)
		return (-1);
	if (!num)
	{
		write(1, "0x0", 3);
		return (3);
	}
	idx = 0;
	while (num && idx < 16)
	{
		result[idx] = hexbase[num % 16];
		num /= 16;
		idx++;
	}
	write (1, "0x", 2);
	count = idx + 2;
	while (--idx >= 0)
		write(1, &result[idx], 1);
	return (count);
}
