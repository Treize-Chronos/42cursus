/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:40:55 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/08 20:11:34 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	pos;
	int	somme;
	int	neg;

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
		somme = somme * 10 + (str[pos] - 48);
		pos++;
	}
	return (somme * neg);
}
