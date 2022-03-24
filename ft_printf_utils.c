/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:00:31 by jabae             #+#    #+#             */
/*   Updated: 2022/03/24 18:14:06 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putnbr_fd(long long num, int fd)
{
	char	strnum;

	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	strnum = num % 10 + 48;
	write(fd, &strnum, 1);
}

char	*ft_make_hex(char c)
{
	char	*hex_base;

	if (c == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	return (hex_base);
}
