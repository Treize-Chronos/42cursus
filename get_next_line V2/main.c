/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:14:14 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/05 14:49:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
		return ;
	write(fd, s, ft_strlen(s));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		ft_putstr_fd(line, 1);
	}
	close(fd);
	return (0);
}