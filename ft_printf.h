/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:26:03 by jabae             #+#    #+#             */
/*   Updated: 2022/03/24 17:46:06 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_switch_format(va_list ap, const char *format, int *idx);

size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(long long num, int fd);
char	*ft_make_hex(char c);

int		ft_putstr_count(char *str);
int		ft_putchar_count(char c);
int		ft_putint_count(long long num);
int		ft_putunsignedint_count(unsigned long long num);
int		ft_puthex_count(unsigned int num, char *hexbase);
int		ft_putpointer_count(unsigned long long num, char *hexbase);

#endif