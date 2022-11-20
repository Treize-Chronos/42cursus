/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 11:50:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_long_nbr_hex(size_t n)
{
	size_t	un;
	char	*set;

	un = n;
	set = "0123456789abcdef";
	if (un > 15)
		ft_put_long_nbr_hex(un / 16);
	ft_putchar(set[un % 16]);
}

int	ft_put_address(size_t n)
{
	ft_putstr("0x");
	ft_put_long_nbr_hex(n);
	return (14);
}
