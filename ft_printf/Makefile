# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 12:06:08 by eguelin           #+#    #+#              #
#    Updated: 2022/11/20 15:08:30 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_nbrlen.c \
		ft_printf.c \
		ft_put_address.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putnbrlen.c \
		ft_putunbr_base.c \
		ft_putunbrlen_base.c \
		ft_unbrlen_base.c \

LIBFT = ./libft/libft.a

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

HEADER = ft_printf.h

CFLAGS	= -Wall -Wextra -Werror -I .

AR		= ar rcs

RM		= rm -f

${NAME}:	${OBJS}
			make all -C ./Libft
			${AR} ${NAME} ${OBJS}

%.o:		%.c ${HEADERS}
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

clean:
			make fclean -C ./Libft
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			make fclean -C ./Libft
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus
