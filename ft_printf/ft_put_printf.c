/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:38:59 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 20:01:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_printf(char c, void *arg)
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
		size = ft_putnbr((int)arg);
	else if (c == 'u')
		size = ft_putnbr_base((unsigned int)arg, 10, "0123456789");
	else if (c == 'x')
		size = ft_putnbr_base((unsigned int)arg, 16, "0123456789abcdef");
	else if (c == 'X')
		size = ft_putnbr_base((unsigned int)arg, 16, "0123456789ABCDEF");
	return (size);
}
