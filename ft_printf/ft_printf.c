/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 12:13:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_ft_printf(char c, void *arg)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar((char)arg);
	else if (c == 's' && arg)
		size = ft_putstr((char *)arg);
	else if (c == 's')
		size = ft_putstr("(null)");
	else if (c == 'p')
		size = ft_put_address((long)arg);
	else if (c == 'd' || c == 'i')
		size = ft_putnbrlen((int)arg);
	else if (c == 'u')
		size = ft_putunbrlen_base((int)arg, 10, "0123456789");
	else if (c == 'x')
		size = ft_putunbrlen_base((int)arg, 16, "0123456789abcdef");
	else if (c == 'X')
		size = ft_putunbrlen_base((int)arg, 16, "0123456789ABCDEF");
	else if (c == '%')
		size = ft_putchar('%');
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	larg;
	int		pos;
	int		size;

	pos = 0;
	size = 0;
	va_start(larg, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			size += put_ft_printf(format[pos + 1], va_arg(larg, void *));
			if (format[pos + 1])
				pos ++;
		}
		else
			size += ft_putchar(format[pos]);
		pos++;
	}
	va_end(larg);
	return (size);
}
