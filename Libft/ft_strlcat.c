/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:00:43 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/17 16:00:54 by eguelin          ###   ########lyon.fr   */
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
		return (ft_strlen(src));
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
	if (dstsize + lensrc < pos - possrc + lensrc && dstsize != (size_t)-1)
		return (dstsize + lensrc);
	else
		return (pos - possrc + lensrc);
}
