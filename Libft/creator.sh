# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Creator.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:57:53 by eguelin           #+#    #+#              #
#    Updated: 2022/11/07 17:14:52 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
gcc -Werror -Wall -Wextra *.c
./a.out 'a'
./a.out '1'
./a.out 'z'
./a.out '9'
./a.out 'A'
./a.out '*'
./a.out 'Z'
./a.out '5'
./a.out 'g'
./a.out '-'
./a.out 'H'
./a.out '@'
./a.out 'q'
./a.out '?'
./a.out 'P'
./a.out 'ç'
rm a.out
