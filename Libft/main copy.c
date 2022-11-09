/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:22:51 by eguelin           #+#    #+#             */
/*   Updated: 2022/11/09 17:05:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>

int main()
{

  int p;
  int o;
  p = strncmp("kpf", "kjf", 546);
  printf("%d",p);
  o = ft_strncmp("kpf", "kjf", 546);
  printf("%d",o);
  return 0;
}
