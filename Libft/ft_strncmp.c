/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:31:27 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 04:21:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (s1[pos] != s2[pos])
			return (s1[pos] - s2[pos]);
		else if (!(s1[pos] && s2[pos]))
			return (0);
		pos++;
	}
	return (0);
}
