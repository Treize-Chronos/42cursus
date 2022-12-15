/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:37:34 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/13 14:32:47 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_prime(int n)
{
	int	x;

	x = 2;
	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	while (x < n / x && n % x)
		x++;
	if (n % x)
		return (1);
	return (0);
}

void	ft_denombre_prime(int n)
{
	int	x;

	x = 2;
	if (n == 0 || n == 1 || ft_prime(n))
	{
		printf("%d", n);
		return ;
	}
	while (1)
	{
		if (ft_prime(x) && !(n % x))
		{
			n = n / x;
			printf("%d x ", x);
			if (ft_prime(n))
			{
				printf("%d", n);
				return ;
			}
			x--;
		}
		x++;
	}
}

int	main(int argc, char const *argv[])
{
	(void) argc;
	ft_denombre_prime(atoi(argv[1]));
	return (0);
}

//int	main(int argc, char const *argv[])
//{
//	(void) argc;
//	printf("%d", ft_prime(atoi(argv[1])));
//	return (0);
//}

//int	main(int argc, char const *argv[])
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	j = 0;
//	(void) argc;
//	while (i != atoi(argv[1]))
//	{
//		j += ft_prime(i);
//		printf("%d = %d\n", i, ft_prime(i));
//		i++;
//	}
//	printf("np = %d", j);
//	return (0);
//}
