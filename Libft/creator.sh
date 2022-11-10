# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    creator.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:57:53 by eguelin           #+#    #+#              #
#    Updated: 2022/11/10 04:59:49 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
gcc -Wall -Wextra -Werror ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c main.c libft.h
./a.out 'a' "-15"
./a.out '1' "742455"
./a.out 'z' "-545325"
./a.out '9' "785723"
./a.out 'A' "-58"
./a.out '*' "1"
./a.out 'Z' "5224"
./a.out '5' "789"
./a.out 'g' "394"
./a.out '-' "-873"
./a.out 'H' "666"
./a.out '@' "83176"
./a.out 'q' "-1454533"
./a.out '?' "-523333"
./a.out 'P' "-4535"
./a.out 'ç' "753315"
rm a.out
rm *.gch
