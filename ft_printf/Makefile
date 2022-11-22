# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 12:06:08 by eguelin           #+#    #+#              #
#    Updated: 2022/11/22 19:51:23 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
		ft_put_address.c \
		ft_put_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbr_base.c \
		ft_putstr.c

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
