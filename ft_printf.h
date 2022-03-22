/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:26:03 by jabae             #+#    #+#             */
/*   Updated: 2022/03/22 01:17:49 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_switch_format(va_list ap, const char *format, int *idx);
int	ft_putchar_count(char c);
int	ft_count_digit(int num);
size_t	ft_strlen(const char *str);
size_t ft_putstr_count(char *str);
void	ft_putnbr_fd(int n, int fd);

#endif