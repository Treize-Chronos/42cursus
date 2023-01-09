/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 19:56:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long un, unsigned long size_set, char *set)
{
	int	count;

	count = 0;
	if (un > size_set - 1)
		count += ft_putnbr_base(un / size_set, size_set, set);
	count += ft_putchar(set[un % size_set]);
	return (count);
}
