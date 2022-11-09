/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:26:15 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/09 16:02:18 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	pos;

	pos = 0;
	if (dst > src)
	{
		while (pos < len)
		{
			((unsigned char *)dst)[len - 1] = ((const unsigned char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (pos < len)
		{
			((unsigned char *)dst)[pos] = ((const unsigned char *)src)[pos];
			pos++;
		}
	}
	return (dst);
}
