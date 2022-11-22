/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:29:12 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/22 14:48:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr(int n);
void	ft_putunbr_base(unsigned int unn, unsigned int size_set, char *set);

int		ft_nbrlen(int n);
int		ft_putchar(char c);
int		ft_putnbrlen(int n);
int		ft_putstr(const char *s);
int		ft_put_address(unsigned long un);
int		ft_put_printf(char c, void *arg);
int		ft_printf(const char *format, ...);
int		ft_unbrlen_base(unsigned long un, unsigned long size_set);
int		ft_putunbrlen_base(unsigned int n, unsigned int size_set, char *set);

#endif
