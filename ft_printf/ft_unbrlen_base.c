/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:02:58 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 14:28:24 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrlen_base(size_t un, size_t size_set)
{
	int	count;

	count = 0;
	if (un == 0)
		count++;
	while (un)
	{
		un /= size_set;
		count++;
	}
	return (count);
}
