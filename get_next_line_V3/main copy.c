/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:14:14 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/06 16:00:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*tmp;
	char static	*memory;

	tmp = NULL;
	if (read_next_line(fd, &memory, &tmp) == -1)
		return (NULL);
	if (!tmp)
	{
		tmp = memory;
		memory = NULL;
		return (tmp);
	}
	return (tmp);
}

int	read_next_line(int fd, char **memory, char **tmp)
{
	int		check;
	char	buf[BUFFER_SIZE];

	check = 0;
	while (!check)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (-1);
		if (check == 0)
			break ;
		if (check != BUFFER_SIZE)
			buf[check] = 0;
		check = check_end(buf, memory, tmp);
		if (check == -1)
			return (-1);
	}
	return (0);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		s = "(null)";
	write(fd, s, ft_strlen(s));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test/nl", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		ft_putstr_fd(line, 1);
	}
	close(fd);
	return (0);
}
