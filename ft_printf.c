/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:05 by jabae             #+#    #+#             */
/*   Updated: 2022/03/23 00:22:10 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //////////// ! 제출 전 빼기

int	ft_switch_format(va_list ap, const char *format, int *idx)
{
	(*idx)++;
	if (format[*idx] == 'd' || format[*idx] == 'i')
		return (ft_putint_count(va_arg(ap, int)));
	else if (format[*idx] == 'u')
		return (ft_putunsignedint_count(va_arg(ap, int)));
	else if (format[*idx] == 'x' || format[*idx] == 'X')
		return (ft_puthex_count(va_arg(ap, int), ft_make_hexbase(format[*idx])));
	else if (format[*idx] == 'p')
		return (ft_putpointer_count(va_arg(ap, unsigned long long), ft_make_hexbase('x')));
	else if (format[*idx] == 's')
		return (ft_putstr_count(va_arg(ap, char *))); //
	else if (format[*idx] == 'c')
		return (ft_putchar_count(va_arg(ap, int))); //
	else if (format[*idx] == '%')
		return (ft_putchar_count('%')); //
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		read_count;
	int		read_buf;
	int		idx;

	va_start(ap, format);
	read_count = 0;
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			read_buf = ft_switch_format(ap, format, &idx);
			if (read_buf < 0)
				return (-1);
			else
				read_count += read_buf;
		}
		else
			read_count += ft_putchar_count(format[idx]);
		idx++;
	}
	va_end(ap);
	return (read_count);
}
