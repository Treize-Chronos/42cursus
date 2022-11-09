/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:21:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 00:09:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;

	pos = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (pos < dstsize - 1)
	{
		dst[pos] = src[pos];
		pos++;
	}
	dst[pos] = 0;
	return (ft_strlen(src));
}
