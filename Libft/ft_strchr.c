/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:04:38 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/14 18:31:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return ((char *)(s + pos));
		pos++;
	}
	if (s[pos] == c)
		return ((char *)(s + pos));
	return (NULL);
}
