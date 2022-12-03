/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:41:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/03 20:58:57 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	size_t			size;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst);

int		count(t_list **lst, char *buf, char **tmp);
int		creat_tmp(char *buf, char **tmp, size_t i, t_list **lst);
int		ft_lstadd_new_back(t_list **lst, char *content, size_t size);

char	*ft_alloc_line(t_list **lst);
char	*ft_lstjion(t_list **lst);
char	*get_next_line(int fd);

#endif
