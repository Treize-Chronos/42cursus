/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:42:39 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/15 20:47:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_unsigned;

	if (n < 0)
	{
		n_unsigned = n * -1;
		ft_putchar('-', fd);
	}
	else
		n_unsigned = n;
	if (n_unsigned >= 10)
		ft_putnbr_fd(n_unsigned / 10, fd);
	ft_putchar((n_unsigned % 10) + 48, fd);
}
