/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:04:38 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/25 13:13:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == (char)c)
			return ((char *)(s + pos));
		pos++;
	}
	if (s[pos] == (char)c)
		return ((char *)(s + pos));
	return (NULL);
}
