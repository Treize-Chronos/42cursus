/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:31:45 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/19 21:46:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbrlen_base(int n, int size_set, char *set)
{
	int	size;

	size = 0;
	ft_putnbr_base(n, size_set, set);
	size = ft_nbrlen_base(n, size_set);
	return (size);
}
