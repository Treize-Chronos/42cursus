/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/23 17:18:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long n)
{
	unsigned long	un;
	int				count;

	un = n;
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		un *= -1;
	}
	if (un > 9)
		count += ft_print_nbr(un / 10);
	count += ft_print_char((un % 10) + '0');
	return (count);
}
