/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/09 13:30:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	larg;
	size_t	pos;
	size_t	size;
	t_list	*print;

	pos = 0;
	size = 0;
	print = NULL;
	va_start(larg, format);
	while (format[pos])
	{
		if (format[pos] == '%')
			ft_print_all(format[pos + 1], larg, &print, &size);
		else
		{
			ft_print_char(format[pos], &size);
		}
		if (format[pos + 1] && format[pos] == '%')
			pos ++;
		pos++;
	}
	va_end(larg);
	return (size);
}
