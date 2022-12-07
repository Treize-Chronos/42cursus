/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:14:14 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/07 17:42:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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

int	creat_tmp(char *buf, char **tmp, size_t i, t_list **lst)
{
	int		pos;

	pos = 0;
	if (!(BUFFER_SIZE - i) || buf[i - 1] != '\n' || !buf[i])
	{
		*tmp = NULL;
		return (1);
	}
	*tmp = malloc(BUFFER_SIZE);
	if (!*tmp)
	{
		ft_lstclear(lst);
		return (-1);
	}
	while (BUFFER_SIZE - i)
		(*tmp)[pos++] = buf[i++];
	(*tmp)[pos] = 0;
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

int	ft_lstadd_new_back(t_list **lst, char *content, size_t size)
{
	t_list	*lstback;
	t_list	*lstnew;

	if (content[size] == '\n')
		size++;
	lstnew = malloc(sizeof(t_list));
	if (!lstnew || !content || !size)
	{
		ft_lstclear(lst);
		return (-1);
	}
	lstnew->content = content;
	lstnew->size = size;
	lstnew->next = NULL;
	if (*lst)
	{
		lstback = *lst;
		while (lstback->next)
			lstback = lstback->next;
		lstback->next = lstnew;
	}
	else
		*lst = lstnew;
	return (0);
}

char	*ft_alloc_line(t_list **lst)
{
	t_list	*lstback;
	size_t	i;
	char	*line;

	if (!*lst || !lst)
		return (NULL);
	lstback = *lst;
	i = 0;
	while (lstback->next)
	{
		i += lstback->size;
		lstback = lstback->next;
	}
	i += lstback->size;
	line = malloc(i + 1);
	if (!line)
	{
		ft_lstclear(lst);
		return (NULL);
	}
	return (line);
}

char	*ft_lstjion(t_list **lst)
{
	char	*line;
	t_list	*lstback;
	size_t	i;
	size_t	j;

	if (!*lst)
		return (NULL);
	line = ft_alloc_line(lst);
	if (!line)
		return (NULL);
	lstback = *lst;
	i = 0;
	while (lstback ->next)
	{
		j = 0;
		while (j < lstback ->size)
			line[i++] = lstback ->content[j++];
		lstback = lstback ->next;
	}
	j = 0;
	while (j < lstback ->size)
		line[i++] = lstback ->content[j++];
	line[i] = 0;
	ft_lstclear(lst);
	return (line);
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
		return ;
	write(fd, s, ft_strlen(s));
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test/multiple_nl.txt", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		ft_putstr_fd(line, 1);
	}
	close(fd);
	return (0);
}
