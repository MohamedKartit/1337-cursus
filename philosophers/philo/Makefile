# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkartit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 12:08:04 by mkartit           #+#    #+#              #
#    Updated: 2024/09/27 12:08:15 by mkartit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC= main.c\
	 utils.c\
	 init.c\
	 simulations.c\
	 actions.c\
	 checker.c\

OBJ=$(SRC:.c=.o)
NAME=philo
CC=gcc
CFLAGS= -Wall -Wextra -Werror
RM=rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
