/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 10:03:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("ft_atoi(%s) = %d\n",argv[1], ft_atoi(argv[1]));
	printf("atoi(%s) = %d\n\n",argv[1], atoi(argv[1]));
	return (0);
}
