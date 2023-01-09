/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:03:35 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/16 15:36:23 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size_tab(char const *s, char c)
{
	int	pos;
	int	count;

	pos = 0;
	count = 0;
	while (s[pos])
	{
		if (s[pos] != c)
			count++;
		while (s[pos] != c && s[pos])
			pos++;
		while (s[pos] == c && s[pos])
			pos++;
	}
	return (count);
}

static int	ft_count_size_cell(char const *s, char c)
{
	int	pos;
	int	count;

	pos = 0;
	count = 0;
	while (s[pos] != c && s[pos])
	{
		pos++;
		count++;
	}
	return (count);
}

static int	ft_complete_cell(char const *s, char **tab, int postab, char c)
{
	int		pos;

	pos = 0;
	tab[postab] = malloc(ft_count_size_cell(s, c) + 1);
	if (!tab[postab])
		return (0);
	while (s[pos] != c && s[pos])
	{
		tab[postab][pos] = s[pos];
		pos++;
	}
	tab[postab][pos] = 0;
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		pos;
	int		postab;

	if (!s)
		return (NULL);
	pos = 0;
	postab = 0;
	tab = malloc(ft_count_size_tab(s, c) * sizeof(tab));
	if (!tab)
		return (NULL);
	while (s[pos])
	{
		while (s[pos] == c && s[pos])
			pos++;
		if (s[pos] != c && s[pos])
		{
			pos += ft_complete_cell(s + pos, tab, postab, c);
			if (!tab[postab])
				return (NULL);
		}
		postab++;
	}
	return (tab);
}
