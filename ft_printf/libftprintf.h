/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:29:12 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/19 21:47:53 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdarg.h>

void	ft_putnbr(int n);
void	ft_putunbr(int n);
int		ft_putchar(char c);
void	ft_putnbr_base(int n, int size_set, char *set);
int		ft_putstr(const char *s);
int		ft_put_address(size_t n);
int		ft_printf(const char *format, ...);
int		ft_nbrlen(int n);
int		ft_nbrlen_base(int n, int size_set);
int		ft_putnbrlen(int n);
int		ft_putnbrlen_base(int n, int size_set, char *set);
#endif
