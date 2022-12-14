/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:18:34 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/17 18:47:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test_set(char c, char const *set)
{
	int	pos;

	pos = 0;
	while (set[pos])
	{
		if (set[pos] == c)
			return (1);
		pos++;
	}
	return (0);
}

static int	ft_pos_start(char const *s1, char const *set)
{
	int	pos;

	pos = 0;
	while (ft_test_set(s1[pos], set) && s1[pos])
		pos++;
	return (pos);
}

static int	ft_pos_end(char const *s1, char const *set)
{
	int	pos;

	pos = ft_strlen(s1) - 1;
	while (ft_test_set(s1[pos], set) && pos)
		pos--;
	return (pos);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		pos;
	int		posstart;
	int		posend;
	char	*s2;

	pos = 0;
	if (!s1 || !set)
		return (NULL);
	posstart = ft_pos_start(s1, set);
	posend = ft_pos_end(s1, set);
	if (posend < posstart)
		posend = posstart - 1;
	s2 = malloc(posend - posstart + 2);
	if (!s2)
		return (NULL);
	pos = 0;
	while (posstart < posend + 1)
	{
		s2[pos] = s1[posstart];
		posstart++;
		pos++;
	}
	s2[pos] = 0;
	return (s2);
}
