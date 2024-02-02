# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkartit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 09:42:21 by mkartit           #+#    #+#              #
#    Updated: 2023/11/21 18:14:00 by mkartit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_printf_utils.c ft_printf.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBC = ar rcs

RM = rm -rf

%.o:%.c
	${CC} ${CFLAGS} -c $<
	${LIBC} ${NAME} $@

all: ${NAME}

${NAME}: ${OBJ}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
