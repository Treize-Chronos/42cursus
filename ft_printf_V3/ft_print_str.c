/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:57:42 by eguelin           #+#    #+#             */
/*   Updated: 2023/01/10 16:49:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_str(char *s, size_t *size, int *error)
{
	char	*s2;

	if (s)
	{
		*size += ft_strlen(s);
		s2 = ft_strdup(s);
	}
	else
	{
		*size += 6;
		s2 = ft_strdup("(null)");
	}
	if (!s2)
	{
		*error = 1;
		return (NULL);
	}
	return (s2);
}
