/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:44:42 by ealtinor          #+#    #+#             */
/*   Updated: 2022/03/03 16:44:44 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr(int n, int *count)
{
	if (n == INT_MIN)
	{
		*count += ft_putchar('-');
		*count += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		*count = ft_putchar('-');
	}
	if (n <= 9)
	{
		*count += ft_putchar((n % 10) + 48);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + 48);
	}
}

void	ft_putbase_decimal(unsigned long n, int *count)
{
	const char	*base;

	base = "0123456789";
	if (n < 0)
		return ;
	if (n <= 9)
	{
		*count += ft_putchar(base[n % 10]);
		return ;
	}
	else
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + 48);
	}
}

void	ft_putbase_hexa(unsigned long n, const char *base, int *count)
{
	if (n < 0)
		return ;
	if (n < 16)
	{
		*count += ft_putchar(base[n % 16]);
		return ;
	}
	else
	{
		ft_putbase_hexa(n / 16, base, count);
		*count += ft_putchar(base[n % 16]);
	}
}
