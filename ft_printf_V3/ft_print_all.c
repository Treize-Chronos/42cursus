/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:38:59 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/10 15:07:56 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_all_2(char c, va_list arg, size_t *size, int *error)
{
	char	*str;

	if (c == 'X')
		str = ft_print_base(va_arg(arg, unsigned int), c, size, error);
	else if (c == '%')
		str = ft_print_char('%', size, error);
	else
		str = NULL;
	return (str);
}

char	*ft_print_all(char c, va_list arg, size_t *size, int *error)
{
	char	*str;

	if (c == 'c')
		str = ft_print_char(va_arg(arg, int), size, error);
	else if (c == 's')
		str = ft_print_str(va_arg(arg, char *), size, error);
	else if (c == 'd' || c == 'i' || c == 'u')
		str = ft_print_int(va_arg(arg, unsigned int), c, size, error);
	else if (c == 'x')
		str = ft_print_base(va_arg(arg, unsigned int), c, size, error);
	else
		str = ft_print_all_2(c, arg, size, error);
	return (str);
}
/*	else if (c == 'p')
		str = ft_print_address(va_arg(arg, long), size);
	*/
