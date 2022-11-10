/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 10:36:40 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("ft_atoi(%d) = %s\n", ft_atoi(argv[1]), argv[1]);
	printf("atoi(%d) = %s\n\n", atoi(argv[1]), argv[1]);
	return (0);
}
