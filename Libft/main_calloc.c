/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 10:26:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int pos;

	pos = 0;
	while (str[pos])
		ft_putchar(str[pos++]);
}

void	ft_putstrlen(char *str, size_t len)
{
	size_t pos;

	pos = 0;
	while (pos < len)
		ft_putchar(str[pos++]);
}

int	main(int argc, char **argv)
{
	(void) argc;
	ft_putstr("ft_calloc(");
	ft_putstr(argv[1]);
	ft_putstr(",");
	ft_putstr(argv[2]);
	ft_putstr(") =");
	ft_putstrlen((char *)(ft_calloc(atoi(argv[1]), atoi(argv[2]))), atoi(argv[1]) * atoi(argv[2]) );
	ft_putstr("\n");
	ft_putstr("calloc(");
	ft_putstr(argv[1]);
	ft_putstr(",");
	ft_putstr(argv[2]);
	ft_putstr(") =");
	ft_putstrlen((char *)(calloc(atoi(argv[1]), atoi(argv[2]))), atoi(argv[1]) * atoi(argv[2]) );
	ft_putstr("\n\n");
	return (0);
}
