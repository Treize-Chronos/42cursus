/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:49:56 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/09 18:19:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lstjion(t_list **lst, size_t size)
{
	char	*line;
	t_list	*lstback;
	size_t	i;
	size_t	j;
	char	*str;

	if (!*lst || !size)
		return (NULL);
	line = malloc(size + 1);
	if (!line)
		return (ft_lstclear(lst, free), NULL);
	lstback = *lst;
	i = 0;
	while (lstback->next)
	{
		j = 0;
		str = (char *)(lstback->content);
		while (str[j])
			line[i++] = str[j++];
		lstback = lstback->next;
	}
	j = 0;
	str = (char *)(lstback->content);
	while (str[j])
		line[i++] = str[j++];
	line[i] = 0;
	return (line);
}
