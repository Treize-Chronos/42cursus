/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:57:15 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/07 13:39:17 by eguelin          ###   ########lyon.fr   */
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
		buf = malloc(BUFFER_SIZE);
		if (!buf)
			return (free(tmp), ft_lstclear(&lst), NULL);
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (free(tmp), free(buf), ft_lstclear(&lst), NULL);
		else if (check == 0)
			return (free(tmp), free(buf), ft_lstjion(&lst));
		check = count(&lst, buf, &tmp);
	}
	return (ft_lstjion(&lst));
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
		if (buf[i] == '\n' || !buf[i] || buf[i] == '\021')
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

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || \
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}
