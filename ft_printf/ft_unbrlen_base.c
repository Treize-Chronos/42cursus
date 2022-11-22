/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:02:58 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 15:13:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrlen_base(unsigned long un, unsigned long size_set)
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
