/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:02:58 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 12:49:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrlen_base(unsigned int un, unsigned int size_set)
{
	int	count;

	count = 0;
	while (un)
	{
		un /= size_set;
		count++;
	}
	return (count);
}
