/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:00:43 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/18 15:20:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	possrc;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	pos = 0;
	possrc = 0;
	if (!dstsize)
		return (lensrc);
	while (dst[pos] && pos <= dstsize - 1)
		pos++;
	while (src[possrc] && pos < dstsize - 1)
	{
		dst[pos] = src[possrc];
		pos++;
		possrc++;
	}
	if (possrc)
		dst[pos] = 0;
	if (dstsize < pos - possrc)
		return (dstsize + lensrc);
	else
		return (pos - possrc + lensrc);
}
