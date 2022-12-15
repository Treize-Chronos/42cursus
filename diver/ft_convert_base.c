/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:24 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/14 16:04:11 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/
static int	ft_nbrlen_base(unsigned long n, size_t set_len)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n = n / set_len;
	}
	return (i);
}

static size_t	check_set(const char *set)
{
	size_t	i;
	size_t	j;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		j = i + 1;
		if (!(set[i] >= 32 && set[i] <= 126))
			return (0);
		while (set[j])
		{
			if (set[i] == set[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

char	*ft_convert_base(unsigned long n, const char *set)
{
	size_t	set_len;
	int		i;
	char	*s;

	set_len = check_set(set);
	if (set_len < 2)
		return (NULL);
	i = ft_nbrlen_base(n, set_len);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i--] = 0;
	while (n)
	{
		s[i--] = set[n % set_len];
		n = (n / set_len);
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
