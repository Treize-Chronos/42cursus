/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:32:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/20 11:51:10 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		i = 42;
	int*	j = &i;

	//ft_printf("\n%d", ft_printf("\n%p", j));
	//printf("\n%d", printf("\n%p", j));
	//ft_printf("\n%d", ft_printf("\n%c", 'j'));
	//printf("\n%d", printf("\n%c", 'j'));
	//ft_printf("\n%d", ft_printf("\n%s", "j"));
	//printf("\n%d", printf("\n%s", "j"));
	//ft_printf("\n%d", ft_printf("\n%d", 42));
	//printf("\n%d", printf("\n%d", 42));
	//ft_printf("\n%d", ft_printf("\n%i", 42));
	//printf("\n%d", printf("\n%i", 42));
	//ft_printf("\n%d", ft_printf("\n%u", 42));
	//printf("\n%d", printf("\n%u", 42));
	//ft_printf("\n%d", ft_printf("\n%x", 42));
	//printf("\n%d", printf("\n%x", 42));
	//ft_printf("\n%d", ft_printf("\n%X", 42));
	//printf("\n%d", printf("\n%X", 42));
	//ft_printf("\n%d", ft_printf("\n%%"));
	//printf("\n%d", printf("\n%%"));
	//ft_printf("\n%d", ft_printf("\n%%"));
	ft_printf("\n%d", ft_printf("\n%c %s %p %d %i %u %x %X %%%", 'p', NULL, j , 4242424242, 4242424242, 4242424242, 4242424242, 4242424242));
	printf("\n%d", printf("\n%c %s %p %d %i %u %x %X %%%", 'p', NULL, j , 4242424242, 4242424242, 4242424242, 4242424242, 4242424242));
	return (0);
}
