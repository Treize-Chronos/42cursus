/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:03:35 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/25 13:33:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_tab(char const *s, char c)
{
	size_t	pos;
	int		count;

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

static size_t	ft_count_word(char const *s, char c)
{
	size_t	pos;
	size_t	count;

	pos = 0;
	count = 0;
	while (s[pos] != c && s[pos])
	{
		pos++;
		count++;
	}
	return (count);
}

static int	ft_complete_word(char const *s, char c, char **tab, int pos)
{
	int		pos_tab;
	size_t	pos_word;

	pos_tab = 0;
	while (s[pos])
	{
		if (s[pos] != c && s[pos])
		{
			pos_word = 0;
			tab[pos_tab] = malloc(ft_count_word(s + pos, c) + 1);
			if (!tab[pos_tab])
				return (pos_tab);
			while (s[pos] != c && s[pos])
			{
				tab[pos_tab][pos_word++] = s[pos++];
			}
			tab[pos_tab++][pos_word] = 0;
		}
		while (s[pos] == c && s[pos])
			pos++;
	}
	tab[pos_tab] = (NULL);
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		pos;
	int		end_free;

	pos = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(tab) * ft_count_tab(s, c));
	if (!tab)
		return (NULL);
	end_free = ft_complete_word(s, c, tab, pos);
	if (end_free != -1)
	{
		while (pos < end_free)
			free(tab[pos++]);
		free(tab);
		return (NULL);
	}
	return (tab);
}
