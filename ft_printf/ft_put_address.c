/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 14:48:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_long_nbr_hex(unsigned long un)
{
	char	*set;

	set = "0123456789abcdef";
	if (un > 15)
		ft_put_long_nbr_hex(un / 16);
	ft_putchar(set[un % 16]);
}

int	ft_put_address(unsigned long un)
{
	ft_putstr("0x");
	ft_put_long_nbr_hex(un);
	return (2 + ft_unbrlen_base(un, 16));
}
