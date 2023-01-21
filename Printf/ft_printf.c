/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:06:36 by ealtinor          #+#    #+#             */
/*   Updated: 2022/03/02 18:06:38 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put(char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (chr == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (chr == 'd' || chr == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (chr == 'u')
		ft_putbase_decimal(va_arg(args, unsigned int), &count);
	else if (chr == 'x')
		ft_putbase_hexa(va_arg(args, unsigned int), "0123456789abcdef", &count);
	else if (chr == 'X')
		ft_putbase_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
	else if (chr == '%')
		count += ft_putchar('%');
	else if (chr == 'p')
	{
		count += ft_putstr("0x");
		ft_putbase_hexa(va_arg(args, unsigned long), "0123456789abcdef",
			&count);
	}
	return (count);
}

int	detect(const char *str, va_list args)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			while (str[i] == ' ')
				i++;
			if (!str[i])
				return (-1);
			count += put(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	count += detect(str, args);
	va_end(args);
	return (count);
}
