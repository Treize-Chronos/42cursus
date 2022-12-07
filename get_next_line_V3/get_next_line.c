/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:57:15 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/06 16:08:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
