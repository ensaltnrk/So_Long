/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:01:21 by ealtinor          #+#    #+#             */
/*   Updated: 2022/02/26 17:01:24 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

int		put(char chr, va_list args);
int		detect(const char *str, va_list args);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int n, int *count);
void	ft_putbase_decimal(unsigned long n, int *count);
void	ft_putbase_hexa(unsigned long n, const char *base, int *count);
#endif
