/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:49:56 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/14 19:14:05 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lstjion(t_list **lst, size_t size)
{
	char	*line;
	t_list	*lstback;
	size_t	i;
	size_t	j;

	if (!*lst ||)
		return (NULL);
	line = malloc(size + 1);
	if (!line)
		return (ft_lstclear(lst), NULL);
	lstback = *lst;
	i = 0;
	while (lstback ->next)
	{
		j = 0;
		while (lstback ->content[j])
			line[i++] = lstback ->content[j++];
		lstback = lstback ->next;
	}
	j = 0;
	while (lstback ->content[j])
		line[i++] = lstback ->content[j++];
	line[i] = 0;
	return (line);
}
