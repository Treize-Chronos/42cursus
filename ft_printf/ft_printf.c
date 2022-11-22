/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 14:43:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	larg;
	int		pos;
	int		size;

	pos = 0;
	size = 0;
	if (write(1, 0, 0) != 0)
		return (-1);
	va_start(larg, format);
	while (format[pos])
	{
		if (format[pos] == '%' && format[pos + 1] != '%')
		{
			size += ft_put_printf(format[pos + 1], va_arg(larg, void *));
		}
		else
			size += write(1, format + pos, 1);
		if (format[pos + 1] && format[pos] == '%')
				pos ++;
		pos++;
	}
	va_end(larg);
	return (size);
}
