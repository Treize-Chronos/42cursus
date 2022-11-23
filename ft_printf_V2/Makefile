# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 12:06:08 by eguelin           #+#    #+#              #
#    Updated: 2022/11/23 17:20:42 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_print_address.c ft_print_all.c ft_print_char.c \
		ft_print_nbr.c ft_print_base.c ft_print_str.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

HEADER = ft_printf.h

CFLAGS	= -Wall -Wextra -Werror -I .

AR		= ar rcs

RM		= rm -f

${NAME}:	${OBJS} Makefile
			${AR} ${NAME} ${OBJS}

%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
