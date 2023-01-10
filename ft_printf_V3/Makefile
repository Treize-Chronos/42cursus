# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 12:06:08 by eguelin           #+#    #+#              #
#    Updated: 2023/01/10 14:35:35 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_lst_utils.c ft_print_address.c ft_print_all.c ft_print_base.c ft_print_char.c ft_print_int.c ft_print_str.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc

HEADER = ft_printf.h

CFLAGS	= -Wall -Wextra -Werror -I .

AR		= ar rcs

RM		= rm -f

${NAME}:	${OBJS}
			make bonus -C ./Libft/
			mv Libft/libft.a ./${NAME}
			${AR} ${NAME} ${OBJS}

%.o:		%.c ${HEADER} Makefile
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
