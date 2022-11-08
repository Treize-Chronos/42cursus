/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:26:15 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/08 20:07:48 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	pos;
	void	*tmp;

	tmp = NULL;
	pos = 0;
	while (pos < len)
	{
		((unsigned char *)tmp)[pos] = ((const unsigned char *)src)[pos];
		pos++;
	}
	pos = 0;
	while (pos < len)
	{
		((unsigned char *)dst)[pos] = ((const unsigned char *)tmp)[pos];
		pos++;
	}
	return (dst);
}
