/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:57:15 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/07 17:45:03 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			check;
	t_list		*lst;
	static char	*tmp;

	lst = NULL;
	check = 0;
	while (check != 1)
	{
		if (!tmp)
		{
			buf = read_next_line(fd, &lst, &check);
			if (!buf)
				return (NULL);
			else if (check == 0)
				return (free(buf), ft_lstjion(&lst));
		}
		else
			buf = tmp;
		check = count(&lst, buf, &tmp);
		if (check == -1)
			return (free(tmp), free(buf), ft_lstclear(&lst), NULL);
	}
	return (ft_lstjion(&lst));
}

char	*read_next_line(int fd, t_list **lst, int *check)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (ft_lstclear(lst), NULL);
	*check = read(fd, buf, BUFFER_SIZE);
	if (*check == -1)
		return (free(buf), ft_lstclear(lst), NULL);
	return (buf);
}

int	count(t_list **lst, char *buf, char **tmp)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n' || !buf[i] || buf[i] == '\021' || buf[i] == '\276')
		{
			if (ft_lstadd_new_back(lst, buf, i) == -1)
				return (-1);
			if (*tmp && !buf[i])
				return (0);
			return (creat_tmp(buf, tmp, i, lst));
		}
		i++;
	}
	return (ft_lstadd_new_back(lst, buf, i));
}
