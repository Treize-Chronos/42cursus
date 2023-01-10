/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:38:59 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/09 19:35:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_all_2(char c, va_list arg, size_t *size)
{
	char	*str;

	if (c == 'X')
		str = ft_print_base(va_arg(arg, unsigned int), c, size);
	else if (c == '%')
		str = ft_print_char('%', size);
	return (str);
}

char	*ft_print_all(char c, va_list arg, size_t *size)
{
	char	*str;

	if (c == 'c')
		str = ft_print_char(va_arg(arg, int), size);
	else if (c == 's')
		str = ft_print_str(va_arg(arg, char *), size);
	else if (c == 'd' || c == 'i' || c == 'u')
		str = ft_print_int(va_arg(arg, unsigned int), c, size);
	else if (c == 'x')
		str = ft_print_base(va_arg(arg, unsigned int), c, size);
	else
		str = ft_print_all_2(c, arg, size);
	return (str);
}
/*	else if (c == 'p')
		str = ft_print_address(va_arg(arg, long), size);
	*/
