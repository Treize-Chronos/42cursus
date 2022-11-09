/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:07:18 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/09 17:53:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		nchar;
	int		len_needle;
	size_t	pos;

	pos = 0;
	nchar = 0;
	len_needle = ft_strlen(needle);
	while (pos < len && nchar < len_needle && !(s1[pos] && s2[pos]))
	{
		if (haystack[pos] == needle[pos])
			nchar++;
		else if (haystack[pos] == needle[0])
			nchar++;
		else
			nchar = 0;
	}
	if (nchar == len_needle)
		return (haystack + pos - len_needle);
	return (NULL);
}
