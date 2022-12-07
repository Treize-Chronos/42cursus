/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:41:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/06 16:03:30 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, size_t size);

int		check_end(char *buf, char **line, char **tmp);
int		read_next_line(int fd, char **memory, char **tmp);
int		dup_end_buf(char *buf, char **memory, char **tmp, size_t size);

size_t	ft_strlen(const char *s);

#endif
