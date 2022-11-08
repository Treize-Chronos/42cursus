/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:18:32 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/08 13:15:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*memcpy(void *dst, const void *src, size_t n)
{
	int pos;

	pos = 0;
	while (pos < n)
	{
		((unsigned char*)dst)[pos] = ((unsigned char*)src)[pos];
		pos++;
	}
}
