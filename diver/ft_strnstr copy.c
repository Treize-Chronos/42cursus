/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:07:18 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/17 13:36:25 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos_h;
	size_t	pos_n;
	size_t	n_char;

	pos_h = 0;
	n_char = ft_strlen(needle);
	while (pos_h < len && haystack[pos_h])
	{
		pos_n = 0;
		while (pos_h + pos_n < len && haystack[pos_h + pos_n] == needle[pos_n])
		{
			pos_n++;
			if (pos_n == n_char)
				return ((char *)(haystack + pos_h));
		}
		if (pos_n == n_char)
			return ((char *)(haystack + pos_h));
		pos_h++;
	}
	if (!pos_h && !n_char)
		return ((char *)(haystack));
	return (NULL);
}
