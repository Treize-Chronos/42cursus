/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 06:44:07 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/10 07:59:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_ncount(int n)
{
	int ncount;

	ncount = 0;
	while (n > 0)
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

	nsize = ft_ncount(n);
	nstr = malloc(nsize + 1);
	if (!nstr)
		return (NULL);
	nstr[nsize] = 0;
	while (nsize > 0)
	{
		nsize--;
		nstr[nsize] = (n % 10) + 48;
		n = n / 10;
	}
	return (nstr);
}
