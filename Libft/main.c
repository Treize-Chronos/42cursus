/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/08 15:24:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <string.h>

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

int	main(int argc, char **argv)
{
	char	str[6] = "55";

	(void) argc;
	ft_putstr("ft_isalpha(");
	ft_putstr(argv[1]);
	ft_putstr(") = ");
	ft_putchar(ft_isalpha(argv[1][0]) + 48);
	ft_putchar('\n');

	ft_putstr("ft_isdigit(");
	ft_putstr(argv[1]);
	ft_putstr(") = ");
	ft_putchar(ft_isdigit(argv[1][0]) + 48);
	ft_putchar('\n');

	ft_putstr("ft_isalnum(");
	ft_putstr(argv[1]);
	ft_putstr(") = ");
	ft_putchar(ft_isalnum(argv[1][0]) + 48);
	ft_putchar('\n');

	ft_putstr("ft_isascii(");
	ft_putstr(argv[1]);
	ft_putstr(") = ");
	ft_putchar(ft_isascii(argv[1][0]) + 48);
	ft_putchar('\n');

	ft_putstr("ft_isprint(");
	ft_putstr(argv[1]);
	ft_putstr(") = ");
	ft_putchar(ft_isprint(argv[1][0]) + 48);
	ft_putstr("\n\n");

	ft_memcpy(str, "ghhjj", 6);
	ft_putstr(str);
	ft_putchar('\n');
	memcpy(str, "ghhjj", 6);
	ft_putstr(str);
	ft_putstr("\n\n");

	return (0);
}
