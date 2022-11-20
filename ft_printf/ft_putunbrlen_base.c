/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrlen_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:31:45 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 12:50:31 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbrlen_base(unsigned int n, unsigned int size_set, char *set)
{
	int	size;

	size = 0;
	ft_putunbr_base(n, size_set, set);
	size = ft_unbrlen_base(n, size_set);
	return (size);
}
