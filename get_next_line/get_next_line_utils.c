/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:46:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/08 17:00:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (s[pos])
		pos++;
	return (pos);
}

char	*ft_strjoin(char *s1, char *s2, size_t size)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1)
		join = malloc(size + 1);
	else
		join = malloc(ft_strlen(s1) + size + 1);
	if (!join)
	{
		free (s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (j < size)
		join[i++] = s2[j++];
	join[i] = 0;
	free (s1);
	return (join);
}

int	ft_check_end_line(char buf[BUFFER_SIZE], char **tmp)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	i = 0;
	j = 0;
	pos = 0;
	while (i < BUFFER_SIZE && buf[i] && buf[i] != '\n')
		i++;
	if (i < BUFFER_SIZE && buf[i] == '\n')
	{
		i++;
		j++;
	}
	if (i)
	{
		*tmp = ft_strjoin(*tmp, buf, i);
		if (!*tmp)
			return (-1);
	}
	while (i < BUFFER_SIZE && j)
		buf[pos++] = buf[i++];
	if (j)
		buf[pos] = 0;
	return (j);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	pos;

	pos = 0;
	while (pos < len)
	{
		((unsigned char *)b)[pos] = c;
		pos++;
	}
	return (b);
}
