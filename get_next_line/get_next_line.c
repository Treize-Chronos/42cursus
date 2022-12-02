/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:57:10 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/02 20:09:43 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char	*get_next_line(int fd)
{
	char	*buf[1];
	int		check;
	t_list	*lst;
	char	*line;

	if (fd < 0)
		return (NULL);
	check = 0;
	lst = NULL;
	while (check != 1)
	{
		*buf = malloc(BUFFER_SIZE);
		check = read(fd, *buf, BUFFER_SIZE);
		if (!check)
		{
			free(*buf);
			ft_lstclear(&lst);
			return (NULL);
		}
		check = jsp(&lst, *buf);
	}
	line = ft_lstjion(&lst);
	ft_lstclear(&lst);
	return (line);
}

int	jsp(t_list	**lst, char *buf)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n' && buf[i])
		{
			if (buf[i] == '\n')
				i++;
			if (ft_lstadd_new_back(lst, buf, i) == -1)
			{
				ft_lstclear(lst);
				return (-1);
			}
			return (1);
		}
		i++;
	}
	if (ft_lstadd_new_back(lst, buf, i) == -1)
	{
		ft_lstclear(lst);
		return (-1);
	}
	return (0);
}
