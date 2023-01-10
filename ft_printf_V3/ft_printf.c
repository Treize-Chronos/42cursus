/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:24:07 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/10 15:01:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(char *format, va_list arg, t_list **print, size_t *size)
{
	char	*str;
	t_list	*lst;
	size_t	pos;
	int		error;

	pos = 0;
	error = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
			str = ft_print_all(format[pos + 1], arg, size, &error);
		else
			str = ft_print_char(format[pos], size, &error);
		lst = ft_lstnew(str);
		ft_lstadd_back(print, lst);
		if (error)
			return (ft_lstclear(print, free), -1);
		if (format[pos + 1] && format[pos] == '%')
			pos ++;
		pos++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	size;
	t_list	*print;
	char	*str;

	size = 0;
	print = NULL;
	va_start(arg, format);
	if (ft_printf_format((char *)format, arg, &print, &size))
		return (-1);
	str = ft_lstjion(&print, size);
	ft_lstclear(&print, free);
	if ((write(1, str, size)) == -1)
		return (-1);
	free(str);
	va_end(arg);
	return (size);
}
