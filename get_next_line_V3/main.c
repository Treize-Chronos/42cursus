/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:14:14 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/06 16:01:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
