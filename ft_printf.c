/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:05 by jabae             #+#    #+#             */
/*   Updated: 2022/03/22 01:35:07 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //////////// ! 제출 전 빼기

int ft_case_di(int format_di)
{
	ft_putnbr_fd(format_di, 1);
	return (ft_count_digit(format_di));
}

unsigned int	ft_putunsigned_count(unsigned int num)
{
	
}

int	ft_switch_format(va_list ap, const char *format, int *idx)
{
	(*idx)++;
	if (format[*idx] == 'd' || format[*idx] == 'i')
		return (ft_case_di(va_arg(ap, int)));
	else if (format[*idx] == 'u')
		return (ft_putunsigned_count(va_arg(ap, int)));
	else if (format[*idx] == 'x' || format[*idx] == 'X')
		return (va_arg(ap, int));
	else if (format[*idx] == 'p')
		return (va_arg(ap, unsigned long long));
	else if (format[*idx] == 's')
		return (ft_putstr_count(va_arg(ap, char *)));
	else if (format[*idx] == 'c')
		return (ft_putchar_count(va_arg(ap, int)));
	else if (format[*idx] == '%')
		return (ft_putchar_count('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		read_count;
	int		read_format;
	int		idx;

	if (!format)
		return (-1);
	va_start(ap, format);
	read_count = 0;
	idx = -1;
	while (format[++idx] != '\0')
	{
		if (format[idx] != '%' && ++read_count)
			write(1, &format[idx], 1);
		else
		{
			read_format = ft_switch_format(ap, format, &idx);
			if (read_format < 0)
				return (-1);
			else
				read_count += read_format;
		}
	}
	va_end(ap);
	return (read_count);
}
