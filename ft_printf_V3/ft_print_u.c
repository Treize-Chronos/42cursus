/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_to_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/14 17:32:15 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (s[pos])
		pos++;
	return (pos);
}
*/
static int	ft_unsigned_nbrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_printf_u(unsigned int n)
{
	char	*s;
	int		i;

	i = ft_unsigned_nbrlen(n);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i--] = 0;
	while (n)
	{
		s[i--] = (n % 10) + '0';
		n = (n / 10);
	}
	return (s);
}
/*
int	main(int argc, char const *argv[])
{
	char	*s;

	(void) argc;
	s = ft_utoa(atoi(argv[1]));
	printf("%s\n%s", s, argv[1]);
	free (s);
	return (0);
}
*/
