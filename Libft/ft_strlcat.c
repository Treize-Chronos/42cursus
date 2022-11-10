/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:00:43 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 02:18:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	pos = lendst;
	if (!dstsize)
		return (ft_strlen(src));
	while (pos < dstsize - 1)
	{
		dst[pos] = src[pos - lendst];
		pos++;
	}
	dst[pos] = 0;
	if (dstsize + lensrc < lendst + lensrc)
		return (dstsize + lensrc);
	else
		return (lendst + lensrc);
}
