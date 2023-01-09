/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/14 17:35:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/

static int	ft_nbrlen(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (c != 'u' && n >= (n * -1))
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_print_int(unsigned int n, char c)
{
	char	*s;
	int		i;

	i = ft_nbrlen(n, c);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i--] = 0;
	if (c != 'u' && n >= (n * -1))
	{
		s[0] = '-';
		n *= -1;
	}
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
	s = ft_print_int(atoi(argv[1]), 'i');
	printf("%s\n%s", s, argv[1]);
	free (s);
	return (0);
}
*/
/*
#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	unsigned int	un;
	int				count;

	un = n;
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		un *= -1;
	}
	if (un > 9)
		count += ft_print_nbr(un / 10);
	count += ft_print_char((un % 10) + '0');
	return (count);
}
*/
