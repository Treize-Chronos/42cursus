/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:46:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/06 15:14:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_end(char *buf, char **line, char **tmp)
{
	size_t	i;

	i = 0;
	while (buf[i] && BUFFER_SIZE > i)
	{
		if (buf[i] == '\n')
		{
			i++;
			if (!dup_end_buf(buf, line, tmp, i))
				return (-1);
			return (1);
		}
		i++;
	}
	*line = ft_strjoin(*line, buf, i);
	if (!line)
		return (-1);
	return (0);
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

int	dup_end_buf(char *buf, char **memory, char **tmp, size_t size)
{
	size_t	pos;

	pos = 0;
	*tmp = ft_strjoin(*memory, buf, size);
	if (!*tmp)
		return (-1);
	if (BUFFER_SIZE - size && !buf[size])
		*memory = NULL;
	else
	{
		*memory = malloc(BUFFER_SIZE - size + 1);
		if (!*memory)
			return (-1);
		while (BUFFER_SIZE - size)
			memory[0][pos++] = buf[size++];
		memory[0][pos] = 0;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (s[pos])
		pos++;
	return (pos);
}
