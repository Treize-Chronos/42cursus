/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:40:55 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/23 11:51:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	check_neg(int neg)
{
	if (neg == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		pos;
	long	somme;
	int		neg;

	pos = 0;
	neg = 1;
	somme = 0;
	while (str[pos] == 32 || (str[pos] >= 9 && str[pos] <= 13))
		pos++;
	if (str[pos] == '-')
	{
		neg *= -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;
	while ((str[pos] >= 48 && str[pos] <= 57))
	{
		if (somme != (somme * 10) / 10)
			return (check_neg(neg));
		somme = somme * 10 + (str[pos] - 48);
		pos++;
	}
	return (somme * neg);
}
