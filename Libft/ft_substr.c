/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/14 20:16:19 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	pos;

	pos = 0;
	s2 = malloc(len + 1);
	if (!s || !s2)
		return (NULL);
	if (start >= ft_strlen(s))
		return (s2);
	while (pos < len)
	{
		s2[pos] = (s + start)[pos];
		pos++;
	}
	s2[pos] = 0;
	return (s2);
}
