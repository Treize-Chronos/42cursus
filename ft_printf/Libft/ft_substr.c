/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 18:00:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	pos;
	size_t	lens;

	if (!s)
		return (NULL);
	pos = 0;
	lens = ft_strlen(s);
	if (start > lens)
		s2 = malloc(1);
	else if (lens - start < len)
		s2 = malloc(lens - start + 1);
	else
		s2 = malloc(len + 1);
	if (!s2)
		return (NULL);
	while (pos < len && pos < lens - start && !(start >= lens))
	{
		s2[pos] = (s + start)[pos];
		pos++;
	}
	s2[pos] = 0;
	return (s2);
}
