/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/09 18:05:28 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/
static int	ft_nbrlen_base(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char	*ft_print_base(unsigned long n, char c, size_t *size)
{
	char	*base;
	int		i;
	char	*s;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = ft_nbrlen_base(n);
	*size += i;
	s = malloc(i + 1);
	if (!s)
	{
		*size = 0;
		return (NULL);
	}
	s[i--] = 0;
	while (n)
	{
		s[i--] = base[n % 16];
		n = (n / 16);
	}
	return (s);
}
/*
int	main(int argc, char const *argv[])
{
	char	*s;

	(void) argc;
	s = ft_convert_base(-1, "01");
	printf("%s\n%d", s, -1);
	free (s);
	return (0);
}*/
/*
int	main(int argc, char const *argv[])
{
	char	*s;

	(void) argc;
	s = ft_convert_base((unsigned int)(atoi(argv[1])), argv[2]);
	printf("%s\n%s", s, argv[1]);
	free (s);
	return (0);
}*/
