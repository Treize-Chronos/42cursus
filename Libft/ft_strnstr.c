/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:07:18 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/17 15:51:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos_h;
	size_t	pos_n;

	pos_h = 0;
	while (pos_h < len && haystack[pos_h])
	{
		pos_n = 0;
		while (pos_h + pos_n < len && haystack[pos_h + pos_n] == needle[pos_n] \
		&& needle[pos_n])
				pos_n++;
		if (!needle[pos_n])
			return ((char *)(haystack + pos_h));
		pos_h++;
	}
	if (!pos_h && !ft_strlen(needle))
		return ((char *)(haystack));
	return (NULL);
}
