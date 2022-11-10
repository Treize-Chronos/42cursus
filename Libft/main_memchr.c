/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 11:18:41 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("ft_memchr(%s,%c,%d) = %s\n", argv[1], argv[2][0], atoi(argv[3]), (char *)ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
	printf("memchr(%s,%c,%d) = %s\n\n", argv[1], argv[2][0], atoi(argv[3]), (char *)memchr(argv[1], argv[2][0], atoi(argv[3])));
	return (0);
}
