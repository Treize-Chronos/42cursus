/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:44:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/14 14:28:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_ncount(int n)
{
	int	ncount;

	ncount = 0;
	if (n <= 0)
	{
		n *= -1;
		ncount++;
	}
	while ((unsigned int)n > 0)
	{
		n = n / 10;
		ncount++;
	}
	return (ncount);
}

char	*ft_itoa(int n)
{
	char	*nstr;
	int		nsize;
	int		neg;

	neg = 0;
	nsize = ft_ncount(n);
	nstr = malloc(nsize + 1);
	if (!nstr)
		return (NULL);
	nstr[nsize] = 0;
	while (nsize > 0)
	{
		if (n < 0)
		{
			n *= -1;
			neg = 1;
		}
		nsize--;
		nstr[nsize] = ((unsigned int)n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		nstr[0] = '-';
	return (nstr);
}
