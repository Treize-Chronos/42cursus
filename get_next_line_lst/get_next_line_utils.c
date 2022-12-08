/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:46:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/08 17:32:30 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
