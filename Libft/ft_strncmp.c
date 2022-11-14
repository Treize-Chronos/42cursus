/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:31:27 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/14 18:49:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if ((unsigned char)s1[pos] != (unsigned char)s2[pos])
			return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
		else if (!((unsigned char)s1[pos] && (unsigned char)s2[pos]))
			return (0);
		pos++;
	}
	return (0);
}
