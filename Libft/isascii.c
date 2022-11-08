/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:56:50 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/08 13:08:11 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii( int c )
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
