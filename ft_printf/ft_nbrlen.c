/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:02:58 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/19 21:34:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nbrlen(int n)
{
	int				pos;
	unsigned int	un;

	un = n;
	pos = 0;
	if (n < 0)
		un *= -1;
	while (n)
	{
		n /= 10;
		pos++;
	}
	return (pos);
}
