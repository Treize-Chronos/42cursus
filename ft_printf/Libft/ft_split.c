/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:03:35 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 15:18:38 by eguelin          ###   ########lyon.fr   */
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
	return (count + 1);
}

static int	ft_count_size_line(char const *s, char c)
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

static int	ft_complete_line(char const *s, char c, char **tab, int pos)
{
	int	postab;
	int	poscell;

	postab = 0;
	while (s[pos])
	{
		if (s[pos] != c && s[pos])
		{
			poscell = 0;
			tab[postab] = malloc(ft_count_size_line(s + pos, c) + 1);
			if (!tab[postab])
				return (postab);
			while (s[pos] != c && s[pos])
			{
				tab[postab][poscell++] = s[pos++];
			}
			tab[postab++][poscell] = 0;
		}
		while (s[pos] == c && s[pos])
			pos++;
	}
	tab[postab] = (NULL);
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		pos;
	int		posfree;

	pos = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(tab) * ft_count_size_tab(s, c));
	if (!tab)
		return (NULL);
	posfree = ft_complete_line(s, c, tab, pos);
	if (posfree != -1)
	{
		while (pos < posfree)
			free(tab[pos++]);
		free(tab);
		return (NULL);
	}
	return (tab);
}
