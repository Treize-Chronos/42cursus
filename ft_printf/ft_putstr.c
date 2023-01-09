/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:22:47 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 20:05:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	pos;

	pos = 0;
	while (s[pos])
	{
		ft_putchar(s[pos]);
		pos++;
	}
	return (pos);
}
