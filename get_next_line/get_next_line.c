/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:57:10 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/02 18:52:46 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf[1];
	int		check;
	t_list	*lst;
	char	*line;

	check = 0;
	lst = NULL;
	while (check != 1)
	{
		*buf = malloc(BUFFER_SIZE);
		check = read(fd, *buf, BUFFER_SIZE);
		if (!check)
			return (NULL);
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
			ft_lstadd_new_back(lst, buf, i);
			return (1);
		}
		i++;
	}
	ft_lstadd_new_back(lst, buf, i);
	return (0);
}
