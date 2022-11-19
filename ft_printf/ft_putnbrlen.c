/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:31:39 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/19 21:46:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbrlen(int n)
{
	int	size;

	size = 0;
	ft_putnbr(n);
	size = ft_nbrlen(n);
	return (size);
}
