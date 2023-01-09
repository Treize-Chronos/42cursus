/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revesword_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:32:56 by eguelin           #+#    #+#             */
/*   Updated: 2022/12/13 17:09:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	first_word(char *str, char *str2, size_t *j)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		str2[(*j)++] = str[i++];
}

int	end_word(char *str, char *str2, size_t *j)
{
	size_t	i;
	size_t	x;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i--;
	while (i && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i--;
	if (i)
		i++;
	x = i;
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		str2[(*j)++] = str[i++];
	return (x);
}

char	*reves_word(char *str)
{
	size_t	i;
	size_t	j;
	size_t	x;
	char	*str2;

	i = 0;
	j = 0;
	str2 = malloc(ft_strlen(str) + 1);
	if (!str2)
		return (NULL);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		str2[j++] = str[i++];
	x = end_word(str, str2, &j);
	while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i])
	{
		while (i < x)
			str2[j++] = str[i++];
		while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		first_word(str, str2, &j);
		while (str[i])
			str2[j++] = str[i++];
	}
	str2[j] = 0;
	return (str2);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	printf("\"%s\" \"%s\"\n", argv[1], reves_word(argv[1]));
	return (0);
}

//"   gjdl;fk fkmeklf ;fjknfl    "
//"012345678901234567890123456789"
//"   lgjdl;fk fkmeklf ;fjknf    "
