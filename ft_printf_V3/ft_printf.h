/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:29:12 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/10 15:11:30 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

int		ft_printf(const char *format, ...);

char	*ft_lstjion(t_list **lst, size_t size);
char	*ft_print_all(char c, va_list arg, size_t *size, int *error);
char	*ft_print_base(unsigned long n, char c, size_t *size, int *error);
char	*ft_print_char(char c, size_t *size, int *error);
char	*ft_print_int(unsigned int n, char c, size_t *size, int *error);
char	*ft_print_str(char *s, size_t *size, int *error);

#endif
