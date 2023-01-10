/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:57:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/10 16:43:52 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_char(char c, size_t *size, int *error)
{
	char	*s;

	s = malloc(2);
	if (!s)
	{
		*error = 1;
		return (NULL);
	}
	*size += 1;
	s[0] = c;
	s[1] = 0;
	return (s);
}
