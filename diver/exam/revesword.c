/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revesword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:56 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/13 17:12:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	revesword(char *str)
{
	size_t	i;
	size_t	j;
	size_t	l;
	size_t	k;
	//char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	printf("%zu\n", i);
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j--;
	l = j;
	while (!(str[j] == ' ' || (str[j] >= 9 && str[j] <= 13)))
		j--;
	j++;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
	{
		k = i;
		while (k < l)
		{
			str[k + 1] = str[k];
			k++;
		}
		i++
	}
	printf("%zu", j);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	revesword(argv[1]);
	return (0);
}

//"   gjdl;fk fkmeklf ;fjknfl    "
//"012345678901234567890123456789"
//"   lgjdl;fk fkmeklf ;fjknf    "
