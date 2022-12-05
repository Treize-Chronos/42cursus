/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:57:15 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/05 15:08:53 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd)
{
	char		*buf[1];
	int			check;
	t_list		*lst;
	char		*line;
	static char	*tmp[1];

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
		check = count(&lst, *buf, tmp);
	}
	line = ft_lstjion(&lst);
	return (line);
}

int	count(t_list **lst, char *buf, char **tmp)
{
	size_t	i;

	i = 0;
	if (*tmp)
		while (tmp[0][i])
			i++;
	if (i)
		if (ft_lstadd_new_back(lst, *tmp, i) == -1)
			return (-1);
	*tmp = NULL;
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n' || !buf[i])
		{
			if (buf[i] == '\n')
				i++;
			if (ft_lstadd_new_back(lst, buf, i) == -1 || \
			!creat_tmp(buf, tmp, i, lst))
				return (-1);
			return (1);
		}
		i++;
	}
	return (ft_lstadd_new_back(lst, buf, i));
}

int	creat_tmp(char *buf, char **tmp, size_t i, t_list **lst)
{
	int		pos;

	pos = 0;
	if (!(BUFFER_SIZE - i) || buf[i - 1] != '\n' || !buf[i])
	{
		*tmp = NULL;
		return (1);
	}
	tmp[0] = malloc(BUFFER_SIZE + 1 - i);
	if (!*tmp)
	{
		ft_lstclear(lst);
		return (-1);
	}
	while (BUFFER_SIZE - i)
		tmp[0][pos++] = buf[i++];
	tmp[0][pos] = 0;
	return (1);
}
