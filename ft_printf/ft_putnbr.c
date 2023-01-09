/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 20:03:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	unsigned long	un;
	int				count;

	un = n;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		un *= -1;
	}
	if (un > 9)
		count += ft_putnbr(un / 10);
	count += ft_putchar((un % 10) + '0');
	return (count);
}
