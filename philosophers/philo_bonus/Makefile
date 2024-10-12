# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkartit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 17:30:48 by mkartit           #+#    #+#              #
#    Updated: 2024/10/01 17:30:49 by mkartit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= main_bonus.c\
	 checker_bonus.c\
	 utils_bonus.c\
	 init_bonus.c\
	 actions_bonus.c\
	 monitoring_bonus.c\
	 simulation_bonus.c\

OBJ = $(SRC:.c=.o)

NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)
